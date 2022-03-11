#include <time.h>
#include <stdio.h>

int main(void){
    char const *week_day[8] = {
        "Sun",
        "Mon",
        "Tue",
        "Wed",
        "Fri",
        "Sat",
        "Unknow",
    };

    struct tm t;
    t.tm_year = 99;
    t.tm_mon = 1;
    t.tm_mday = 0;
    t.tm_hour = 0;
    t.tm_min = 0;
    t.tm_sec = 1;
    t.tm_isdst = -1;
    if(mktime(&t)==-1)
        t.tm_wday = 7;
    printf("The day is:%s", week_day[t.tm_wday]);

    getchar();
    return 0;
}