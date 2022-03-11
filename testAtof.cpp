#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char const *str = "12345.67";
    float result;
    result = atof(str);
    printf("string=%s\nfloat=%f\n", str, result);
    getchar();
    return 0;
}
