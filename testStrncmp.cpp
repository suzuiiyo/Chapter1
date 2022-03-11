#include <string.h>
#include <stdio.h>

int main(void)
{
    char const *str1 = "Hello World";
    char const *str2 = "Hello C Programme";
    int result;
    result = strncmp(str1, str2, 5);
    if(!result)
        printf("%s is identical to %s in the first 5 words", str1, str2);
    else if(result <0)
        printf("%s is less than %s in the first 5 words", str1, str2);
    else
        printf("%s is great than %s in the first 5 words", str1, str2);

    printf("\n");

    result = strncmp(str1, str2, 10);
    if(!result)
        printf("%s is identical to %s in the first 10 words", str1, str2);
    else if(result <0)
        printf("%s is less than %s in the first 10 words", str1, str2);
    else
        printf("%s is great than %s in the first 10 words", str1, str2);

    getchar();
    return 0;
}
