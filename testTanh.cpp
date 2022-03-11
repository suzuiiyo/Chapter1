#include <stdio.h>
#include <math.h>

int main(void){
    double result, x;
    x = 0.5;
    result = tanh(x);
    printf("th(%lf)=%lf\n", x, result);
    return 0;
}