#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *str = "12345.67";
    long result;
    result = atol(str);
    printf("string=%s\nlong=%ld\n", str, result);
    getchar();
    return 0;
}