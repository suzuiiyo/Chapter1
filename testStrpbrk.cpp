#include <stdio.h>
#include <string.h>

int main(void){
    char const *str1 = "There are 5 pigs in the hogpen";
    char const *str2 = "0123456789";
    char *result;
    result = strpbrk(str1, str2);
    if(result)
    {
        printf("%s\n", result++);
    }
    else
    {
        printf("There are no numbers any more");
    }
    result = strpbrk(result, str2);
    if(result)
        printf("%s\n", result++);
    else
        printf("There are no numbers any more");

    getchar();
    return 0;
}