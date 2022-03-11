#include <math.h>
#include <stdio.h>

int main(void){
    long x = -12345678L;
    printf("number:%ld absolute value:%ld\n", x, labs(x));
    return 0;
}