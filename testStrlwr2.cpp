#include <stdio.h>
#include <string.h>

int main(){
    char str[20];

    printf("Enter string: ");
    fgets(str, 20, stdin);
    printf("String is: %s\n", str);
    // printf("Long String is: %s\n", strlwr(str));

    return 0;
}