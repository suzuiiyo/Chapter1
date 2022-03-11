#include <stdio.h>
#include <string.h>

int main(void)
{
    char src1[3] = {""}, src2[10] = {"Hello"};
    char const *src3 = "Hello";
    printf("%d\n", strlen(src1));
    printf("%d\n", strlen(src2));
    printf("%d\n", strlen(src3));

    getchar();
    return 0;
}