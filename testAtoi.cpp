#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char const *str = "12345.667";
    int result;
    result = atoi(str);
    printf("string=%s\ninteger=%d\n", str, result);
    getchar();
    return 0;
}