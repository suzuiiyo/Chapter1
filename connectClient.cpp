#include <sys/socket.h>
#include <sys/types.h>
#include "netdb.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <unistd.h>
#include "rio.h"

#define MAXLINE 100

int open_clientfd(char *, char *);

int main(int argc, char **argv){
    int clientfd;
    char *host, *port, buf[MAXLINE];
    rio_t rio;
    if(argc != 3){
        fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
        exit(0);
    }

    host = argv[1];
    port = argv[2];

    clientfd = open_clientfd(host, port);
    rio_readinitb(&rio, clientfd);

    while(fgets(buf, MAXLINE, stdin)!=NULL){
        rio_writen(clientfd, buf, strlen(buf));
        rio_readlineb(&rio, buf, MAXLINE);
        fputs(buf, stdout);
    }
    close(clientfd);
    exit(0);
}

int open_clientfd(char* hostname, char* port){
    int clientfd;
    struct addrinfo hints, *listp, *p;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_NUMERICSERV;
    hints.ai_flags |= AI_ADDRCONFIG;
    getaddrinfo(hostname, port, &hints, &listp);
    //getaddrinfo 会返回所有可用的套接字
    for (p = listp; p;  p = p->ai_next)
    {
        if((clientfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol))<0)
            continue;
        if(connect(clientfd, p->ai_addr, p->ai_addrlen)!=-1)        //参数分别为客户端的文件描述符，addr地址结构
            break;                          //成功建立连接
        close(clientfd);                    //建立失败，尝试另一个套接字    
    }

    freeaddrinfo(listp);
    if(!p)
        return -1;
    return clientfd;
}
