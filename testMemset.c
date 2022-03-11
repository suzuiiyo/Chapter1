#include <string.h>
#include <stdio.h>

int main(void){
    char str[] = "AAAAAAAAAAAAAAAAAAAAA";
    printf("%p\n", str);
    printf("The original string is:     %s\n", str);
    memset(str, 'B', 8);
    printf("The string after memset is:%s     \n", str);

    printf("%lld\n", strlen(str));
}