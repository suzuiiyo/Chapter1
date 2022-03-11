#include <math.h>
#include <stdio.h>

int main(void){
    double result;
    double x = M_E;
    result = log(x);
    printf("The natural log of %lf is %lf\n", x, result);

    return 0;
}