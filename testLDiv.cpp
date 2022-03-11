#include <stdlib.h>
#include <stdio.h>

ldiv_t lx;

int main(void)
{
    lx = ldiv(200000L, 70000L);
    printf("200000 div 70000 = %ld remainder %ld\n", lx.quot, lx.rem);

    return 0;
}