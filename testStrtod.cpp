#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    char str[20], *endptr;
    double result;
    while(1)
    {
        printf("Input a float:");
        fgets(str, strlen(str), stdin);
        result = strtod(str, &endptr);
        if(result!=-1)
            printf("The number is %lf\n", str, result);
        else
            break;
    }
    getchar();
    return 0;
}