#include <stdio.h>
#include <math.h>

int main(void){
    double result, x;
    x = M_PI / 4;
    result = tan(x);
    printf("tan(PI/4)=%lf\n", result);

    return 0;
}