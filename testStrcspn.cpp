#include <string.h>
#include <stdio.h>

int main(void)
{
    char const *str1 = "tomato", *str2 = "carrot";
    char const *str = "abc";
    int result;
    result = strcspn(str1, str);

    if(result)
        printf("The first %d is congruent\n", result);
    else
        printf("No character is congruent\n");

    result = strcspn(str2, str);

    if(result)
        printf("The first %d is congruent\n", result);
    else
        printf("No character is congruent\n");

    getchar();
    return 0;
}