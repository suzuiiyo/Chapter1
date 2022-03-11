#include <sys/socket.h>
#include <sys/types.h>
#include <sys/select.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <unistd.h>
#include <errno.h>
#include "rio.h"

#define LISTENQ 1024
#define MAXLINE 100

typedef struct{
    int maxfd;
    fd_set read_set;
    fd_set ready_set;
    int nready;
    int maxi;
    int clientfd[FD_SETSIZE];
    rio_t clientrio[FD_SETSIZE];
} pool;

int bytes_cnt = 0;

int open_listenfd(char *);
void echo(int);
void command();
void init_pool(int, pool *);
void add_client(int, pool *);
void check_clients(pool *);

int main(int argc, char** argv){
    int listenfd, connfd;
    socklen_t clientlen;
    struct sockaddr_storage clientaddr;
    char client_hostname[MAXLINE];
    char client_port[MAXLINE];
    static pool pool;

    if(argc != 2){
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(0);
    }

    listenfd = open_listenfd(argv[1]);
    init_pool(listenfd, &pool);

    while(1){
        pool.ready_set = pool.read_set;
        pool.nready = select(pool.maxfd + 1, &pool.ready_set, NULL, NULL, NULL);

        if(FD_ISSET(listenfd, &pool.ready_set)){
            clientlen = sizeof(struct sockaddr_storage);
            connfd = accept(listenfd, (struct sockaddr *)&clientaddr, &clientlen);
            add_client(connfd, &pool);
            getnameinfo((struct sockaddr *)&clientaddr, clientlen, client_hostname, MAXLINE, client_port, MAXLINE, 0);
            printf("连接到:(%s, %s)\n", client_hostname, client_port);
        }

        check_clients(&pool);
    }
}

int open_listenfd(char* port){
    int listenfd;
    int optval = 1;
    struct addrinfo hints, *listp, *p;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE | AI_ADDRCONFIG;
    hints.ai_flags |= AI_NUMERICSERV;
    getaddrinfo(NULL, port, &hints, &listp);
    for (p = listp; p; p=p->ai_next){
        if((listenfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0)
            continue;
        setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval, sizeof(int));
        if(bind(listenfd, p->ai_addr, p->ai_addrlen) == 0)
            break;
        close(listenfd);
    }

    freeaddrinfo(listp);
    if(!p)
        return -1;
        //建立成功，开始监听
        //LISTENQ是等待的链接请求队列
    if(listen(listenfd, LISTENQ)<0){
        close(listenfd);
        return -1;
    }

    return listenfd;
}

void echo(int connfd){
    size_t n;
    char buf[MAXLINE];
    rio_t rio;
    rio_readinitb(&rio, connfd);
    while((n = rio_readlineb(&rio, buf, MAXLINE)!= 0)){
        printf("服务器接收到: %d字节\n", (int)n);
        printf("%s\n", buf);
        rio_writen(connfd, buf, n);
    }
}

void command(){
    char buf[MAXLINE];
    if(!fgets(buf, MAXLINE, stdin))
        exit(0);
    printf("%s", buf);
}

void init_pool(int listenfd, pool* p){
    int i;
    p->maxi = -1;
    for (i = 0; i < FD_SETSIZE; i++)
        p->clientfd[i] = -1;
    p->maxfd = listenfd;
    FD_ZERO(&p->read_set);
    FD_SET(listenfd, &p->read_set);
}

void add_client(int connfd, pool* p){
    int i;
    p->nready--;
    for (i = 0; i < FD_SETSIZE; i++){
        if(p->clientfd[i]<0){
            p->clientfd[i] = connfd;
            rio_readinitb(&p->clientrio[i], connfd);

            FD_SET(connfd, &p->read_set);
            if(connfd > p->maxfd)
                p->maxfd = connfd;
            if(i > p->maxi)
                p->maxi = i;
            break;
        }
    }
    if(i == FD_SETSIZE)
        printf("add_client error: 客户端过多");
}

void check_clients(pool* p){
    int i, connfd, n;
    char buf[MAXLINE];
    rio_t rio;
    for (i = 0; i < p->maxi && p->nready > 0; i++){
        connfd = p->clientfd[i];
        rio = p->clientrio[i];

        if((connfd>0) && (FD_ISSET(connfd, &p->ready_set))){
            p->nready--;
            if((n = rio_readlineb(&rio, buf, MAXLINE))!=0){
                bytes_cnt += n;
                printf("服务器收到%d (总共%d) 字节在文件描述符%d", n, bytes_cnt, connfd);
                rio_writen(connfd, buf, n);
                printf("内容:%s\n", buf);
            }
            else{
                close(connfd);
                FD_CLR(connfd, &p->read_set);
                p->clientfd[i] = -1;
            }
        }
    }
}
