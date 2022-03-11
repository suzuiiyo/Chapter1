#pragma once

#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>
//a buffer named rio_t

#define RIO_BUFSIZE 4096

typedef struct {
    int rio_fd; 
    int rio_cnt; //unread bytes in rio_buf
    char *rio_bufptr; //next unread byte in rio_buf
    char rio_buf[RIO_BUFSIZE]; //internal buffer
} rio_t;

void rio_readinitb(rio_t *rp, int fd)
/**
 * @brief rio_read  RIO--Robust I/O包 底层读取函数。当缓冲区数据充足时，此函数直接拷贝缓
 *                  冲区的数据给上层读取函数。当缓冲区不足时，该函数通过系统调用
 *                  从文件里读取最大数量的字节到缓冲区，再拷贝缓冲区数据给上层函数
 *
 * @param rp        rio_t，里面包括了文件描写叙述符和其相应的缓冲区数据
 * @param usrbuf    读取的目的地址
 * @param n         读取的字节数量
 *
 * @returns         返回真正读取到的字节数（<=n）
 */
{
    rp->rio_fd = fd;
    rp->rio_cnt = 0;
    rp->rio_bufptr = rp->rio_buf;

    return;
}

static ssize_t rio_read(rio_t *rp, char *usrbuf, size_t n)
/**
 * @brief rio_read  RIO--Robust I/O包 底层读取函数。当缓冲区数据充足时，此函数直接拷贝缓
 *                  冲区的数据给上层读取函数。当缓冲区不足时，该函数通过系统调用
 *                  从文件里读取最大数量的字节到缓冲区，再拷贝缓冲区数据给上层函数
 *
 * @param rp        rio_t，里面包括了文件描写叙述符和其相应的缓冲区数据
 * @param usrbuf    读取的目的地址
 * @param n         读取的字节数量
 *
 * @returns         返回真正读取到的字节数（<=n）
 */
{
    int cnt;
    while(rp->rio_cnt <= 0)
    {
        rp->rio_cnt = read(rp->rio_fd, rp->rio_buf, sizeof(rp->rio_buf));
        if(rp->rio_cnt < 0)
        {
            if(errno != EINTR)  //遇到中断类型错误的话应该进行读取，否则就返回错误
                return -1;
        }
        else if(rp->rio_cnt == 0)      //读取到了EOF
            return 0;
        else 
            rp->rio_bufptr = rp->rio_buf;       //重置bufptr指针，令其指向第一个未读取字节，然后便退出循环
    }

    cnt = n;
    if((size_t)rp->rio_cnt < n)
        cnt = rp->rio_cnt;
    memcpy(usrbuf, rp->rio_bufptr, n);
    rp->rio_bufptr += cnt;          //读取后需要更新指针
    rp->rio_cnt -= cnt;             //未读取字节也会降低

    return cnt;
}

ssize_t rio_readnb(rio_t *rp, void *usrbuf, size_t n)
/**
 * @brief rio_readnb    供用户使用的读取函数。从缓冲区中读取最大maxlen字节数据
 *
 * @param rp            rio_t，文件描写叙述符与其相应的缓冲区
 * @param usrbuf        void *, 目的地址
 * @param n             size_t, 用户想要读取的字节数量
 *
 * @returns             真正读取到的字节数。读到EOF返回0,读取失败返回-1。
 */
{
    size_t leftcnt = n;
    ssize_t nread;
    char *buf = (char *)usrbuf;

    while(leftcnt > 0)
    {
        if((nread = rio_read(rp, buf, n)) < 0)
        {
            if(errno == EINTR)          //事实上这里能够不用推断EINTR,rio_read()中已经对其处理了
                nread = 0;
            else
                return -1;
        }
        leftcnt -= nread;
        buf += nread;
    }

    return n - leftcnt;
}

ssize_t rio_readlineb(rio_t *rp, void *usrbuf, size_t maxlen)
/**
 * @brief rio_readlineb 读取一行的数据，遇到'\n'结尾代表一行
 *
 * @param rp            rio_t包
 * @param usrbuf        用户地址，即目的地址
 * @param maxlen        size_t, 一行最大的长度。若一行数据超过最大长度，则以'\0'截断
 *
 * @returns             真正读取到的字符数量
 */
{
    size_t n;
    int rd;
    char c, *bufp = (char *)usrbuf;

    for (n = 1; n < maxlen; n++)
    {
        if((rd=rio_read(rp, &c, 1)) == 1)
        {
            *bufp++ = c;
            if(c == '\n')
                break;
        }
        else if(rd == 0)        //没有接收到数据
        {
            if(n == 1)          //假设第一次循环就没有接收到数据，则代表无数据可接受
                return 0;
            else
                break;
        }
        else
            return -1;
    }
    *bufp = 0;

    return n;
}

ssize_t rio_writen(int fd, void *usrbuf, size_t n)
{
    size_t nleft = n;
    ssize_t nwritten;
    char *bufp = (char *)usrbuf;

    while(nleft > 0)
    {
        if((nwritten = write(fd, bufp, nleft)) <= 0)
        {
            if(errno == EINTR)
                nwritten = 0;
            else
                return -1;
        }
        bufp += nwritten;
        nleft -= nwritten;
    }

    return n;
}