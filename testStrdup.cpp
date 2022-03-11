#include <stdio.h>
#include <string.h>

int main(void)
{
    char const *src = "This is the buffer text";
    char *dest;

    dest = strdup(src);
    if(!strcmp(src, dest))
        printf("Copy success\n%s\n", dest);
    else
        printf("Copy failure");
    // free(dest);
    getchar();
    return 0;
}