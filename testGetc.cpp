#include <stdio.h>
int main(void)
{
    char ch;
    printf("input a character:");
    ch = getc(stdin);
    printf("The character input was: '%c'\n", ch);
    return 0;
}