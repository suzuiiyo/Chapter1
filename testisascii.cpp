#include <stdio.h>
#include <ctype.h>

int main(void){
    int c;
    c = 'A';
    printf("%c:%s\n", c, __isascii(c) ? "yes" : "no");
    c = 0x7f;
    printf("%c:%s\n", c, __isascii(c) ? "yes" : "no");
    c = 0x80;
    printf("%c:%s\n", c, __isascii(c) ? "yes" : "no");
    getchar();
    return 0;
}


