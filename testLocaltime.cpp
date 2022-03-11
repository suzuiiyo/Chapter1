#include <time.h>
#include <stdio.h>
// #include <dos.h>

//asctime(localtime(&time)) == ctime(&time)
int main(void){
    time_t timer;
    struct tm *tblock;
    timer = time(NULL);
    tblock = localtime(&timer);
    printf("Local time is:%s\n", asctime(tblock));
    printf("Today's date and time: %s \n", ctime(&timer));

    getchar();
    return 0;
}
