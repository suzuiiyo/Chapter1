#include <stdio.h>
#include <string.h>

int main(void){
    char const *str1 = "Borland International", *str2 = "nation";
    char *result;
    result = strstr(str1, str2);
    if(result)
        printf("The substring is: %s\n", str2);
    else
        printf("Not found the substring");
    getchar();
    return 0;
}