#include <string.h>
#include <stdio.h>

int main(void)
{
    char str[15] = {""};
    char *ptr, c = 'r';
    strcpy(str, "Hello World");
    ptr = strchr(str, c);
    if(ptr)
        printf("The character %c is at position: %d\n", c, ptr - str);
    else
        printf("The character was not found\n");

    strcpy(str, "Aloha");

    if(ptr)
        printf("The character %c is at position: %d\n", c, ptr - str);
    else
        printf("The character was not found\n");
    getchar();
    return 0;
}