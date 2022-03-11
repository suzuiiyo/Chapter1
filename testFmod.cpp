#include <stdio.h>
#include <math.h>

int main(void)
{
    float x, y;
    x = 12.580000;
    y = 2.6000000;

    printf("12.580000/2.600000: %f\n", fmod(x, y));
    getchar();
    return 0;
}
