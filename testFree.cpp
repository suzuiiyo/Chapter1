#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    char *p;
    p = (char *)malloc(10 * sizeof(char));
    strcpy(p, "Hello world\n");
    printf("%s", p);
    free(p);
    p = NULL;
    printf("%s", p);
}