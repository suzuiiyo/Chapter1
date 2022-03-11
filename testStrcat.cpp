#include <string.h>
#include <stdio.h>

int main()
{
    char dest[20] = {"  "};
    char const *hello = "hello ", *space = " ", *world = "world";
    strcat(dest, hello);
    strcat(dest, space);
    strcat(dest, world);
    printf("%s\n", dest);
    getchar();
    return 0;
}