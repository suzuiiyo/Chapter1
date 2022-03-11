
#include <time.h>
#include <stdio.h>

int main(void)
{
    time_t t;
    t = time(&t);
    printf("The number of seconds since January 1, 1070 is %ld", t);
    return 0;
}