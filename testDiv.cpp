#include <stdlib.h>
#include <stdio.h>

div_t x;

int main(void){
    x = div(11, 5);
    printf("11 div 5=%d remainder %d\n", x.quot, x.rem);

    return 0;
}