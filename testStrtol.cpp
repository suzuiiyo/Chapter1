#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char str[20], *endptr;
    long result;
    while(1)
    {
        printf("Input a long:");
        fgets(str, strlen(str), stdin);
        printf("str == %s", str);
        result = strtod(str, &endptr);
        if(result!=-1){
            printf("The number is %ld\n", result);
        }else{
            break;
        }
    }

    getchar();
    return 0;
}