#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int i = 0;
    char ch;
    puts("input an integer followed by a char:");
    while((ch = getchar())!=EOF && isdigit(ch))
        i = 10 * i + ch - 48;
    if(ch!= EOF)
        ungetc(ch, stdin);
    printf("i = %d, next char in buffer = %c\n", i, getchar());
    return 0;
}