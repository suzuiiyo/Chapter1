#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846

int main(void)
{
    char str[80];
    sprintf(str, "An approximatrion of Pi is %f\n", M_PI);
    puts(str);
    return 0;
}