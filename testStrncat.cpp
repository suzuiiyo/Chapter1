#include <string.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    char dest[30] = {""};
    char const *favorite = "I love", *tabs = "\t\n", *language = "C++";
    strncat(dest, favorite, 6);
    strncat(dest, tabs, 1);
    strncat(dest, language, 3);
    printf("%s\n", dest);
    getchar();
    return 0;
}