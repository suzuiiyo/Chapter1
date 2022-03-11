#include <string.h>
#include <stdio.h>

int main(void)
{
    char str[] = "AAAAAAAAAAAAAAAAAAAAAA";
    printf("The original string is:         %s\n", str);
    memset(str, 'B', 9);
    printf("The string after memset is:%s     \n", str);
}