#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846
int main(void)
{
    double result;
    double x = M_PI;
    result = cos(x);
    printf("cos(PI) is %lf\n", result);
    return 0;
}