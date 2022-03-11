#include <math.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    double num = 123.4000000;
    double up;
    up = ceil(num);
    printf("The original number  %lf\n", num);
    printf("The num rounded up   %lf\n", up);

    return 0;
}