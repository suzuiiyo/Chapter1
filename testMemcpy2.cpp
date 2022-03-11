#include <string.h>
#include <stdio.h>

int main(void){
    char *d = "1234567890";
    char *p;

    p = d + 3;
    printf("%s\n", d);
    memcpy(p, d, 6);
    printf("%s\n", d);
    return 0;
}