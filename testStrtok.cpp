#include <stdio.h>
#include <string.h>

int main(void)
{
    char *str1 = "I am very\thappy, to, study\nC\nprogramme";
    char *str2 = " ,\t\n";
    char *token;
    printf("%s\n\nTokens:\n", str1);
    token = strtok(str1, str2);
    while(token != NULL){
        printf("%s\n, token");
        token = strtok(NULL, str2);
    }

    getchar();
    return 0;
}