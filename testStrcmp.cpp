#include <string.h>
#include <stdio.h>

int main(void)
{
    char const *str1 = "Canada", *str2 = "China", *str3 = "china";
    int result;
    result = strcmp(str1, str2);
    printf("result = %d\n", result);
    if (result < 0)
        printf("%s is less than %s", str1, str2);
    else
        printf("%s is not less than %s", str1, str2);

    printf("\n");
    result = strcmp(str2, str3);
    printf("result = %d\n", result);
    if(result < 0)
        printf("%s is less than %s", str2, str3);
    else
        printf("%s is not less than %s", str2, str3);

    getchar();
    return 0;
}