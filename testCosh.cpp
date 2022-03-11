#include <stdio.h>
#include <math.h>

int main(void)
{
    double result;
    double x = 0.5;
    result = cosh(x);
    printf("ch(%lf)=%lf\n", x, result);

    return 0;
}