#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[15] = {""};

    char const *ptr, c = 'o';
    strcpy(str, "Hello World");
    ptr = strchr(str, c);
    if(ptr)
        printf("The first character %c is at position: %ld\n", c, ptr - str);
    else
        printf("The character was not found\n");

    ptr = strchr(str, c);
    if(ptr)
        printf("The last character %c is at position: %ld\n", c, ptr - str);
    else
        printf("The character was not found\n");

    getchar();
    return 0;
}