#include <stdio.h>
#include <string.h>

int main(void){
    char dest[20] = {""};
    char const*src1 = "Hello World", *src2 = "Aloha";
    strncat(dest, src1, 5);

    strncat(dest, src2, 5);

    if(!strcmp(dest, src1))
        printf("dest is equal to src1\n");
    else if(!strcmp(dest, src2))
        printf("dest is equal to src2\n");
    else
        printf("dest is %s\n", dest);

    printf("%s\n", dest);
    getchar();
    return 0;
}