#include <stdio.h>
#include <string.h>

int main(void)
{
    char dest[20] = {""};
    char const *src = "Hello World";
    int result;
    strcpy(dest, src);
    printf("%s\n", dest);
    result = strcmp(dest, src);
    if(!result)
        printf("dest is equal to src");
    else
        printf("dest is not equal to src");

    getchar();
    return 0;
}
