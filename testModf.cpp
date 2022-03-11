
#include <math.h>
#include <stdio.h>
int main(void)
{
    double fraction, integer;
    double number = 12345.6789;
    fraction = modf(number, &integer);
    printf("The integer and the fraction of %lf are %lf and %lf\n", number, integer, fraction);

    return 0;
}