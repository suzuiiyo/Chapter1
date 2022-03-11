#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char c, ch;
    printf("Input some character until control character\n");
    scanf("%c", &c);
    ch = getchar();
    while(!iscntrl(c)){
        scanf("%c", &c);
        ch = getchar();
    }
    return 0;
}