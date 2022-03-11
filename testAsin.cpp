#include <stdio.h>
#include <math.h>

int main(void)
{
    double result;
    double x = 1.0;
    result = asin(x);
    printf("arcsin %lf %lf\n", x, result);

    return 0;
}