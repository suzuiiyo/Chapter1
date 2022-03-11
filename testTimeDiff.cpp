#include <time.h>
#include <stdio.h>
#include <unistd.h>

int mian(void){
    time_t first, second;
    // clrscr();
    //获得系统时间
    first = time(NULL);
    sleep(2);
    second = time(NULL);
    printf("The interval is: %f seconds   \n", difftime(second, first));
    getchar();
    return 0;
}