#include <math.h>
#include <stdio.h>

int main(void)
{
    double num = 123.40000;
    double up;
    up = floor(num);
    printf("The original number  %lf\n", num);
    printf("THe num rounded down  %lf\n", up);

    return 0;
}