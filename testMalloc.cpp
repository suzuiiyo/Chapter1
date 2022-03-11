#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(){
    char *str;
    if((str = (char *)malloc(15)) == NULL)
    {
        printf("Not enough memory to allocate buffer\n");
        exit(1);
    }
    strcpy(str, "Hello World!");
    printf("String is %s\n", str);
    free(str);
    return 0;
}