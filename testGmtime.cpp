#include <stdio.h>
#include <stdlib.h>

#include <time.h>

int main(void){
    time_t t;
    struct tm *gmt;
    t = time(NULL);
    gmt = gmtime(&t);
    printf("GMT is:%s", asctime(gmt));

    return 0;
}