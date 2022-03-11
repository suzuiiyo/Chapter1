#include <stdio.h>
#include <math.h>

int main(void)
{
    float x;
    int exp;
    x = frexp(64.0, &exp);
    printf("64.0=%.2f*2^%d", x, exp);
    getchar();
    return 0;
}