#include <stdio.h>
#include <math.h>

int main(void)
{
    double value;
    double x = 3.000000;
    value = ldexp(x, 3);
    printf("The ldexp value is: %lf\n", value);
    getchar();
    return 0;
}