#include <string.h>
#include <stdio.h>

int main(void)
{
    char const *str1 = "cabbage", *str2 = "potato";
    char const *str = "abc";
    int result;
    result = strspn(str1, str);

    if(result){
        printf("The first %d is congruent\n", result);
    }
    else{
        printf("No character is congruent");
    }
    result = strspn(str2, str);
    if(result)
        printf("The first %d is congruent\n", result);
    else
        printf("No character is congruent");

    getchar();
    return 0;
}