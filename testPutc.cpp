#include <stdio.h>

int main(void)
{
    char str[] = "Hello world!";
    int i = 0;
    while(str[i])
    {
        putc(str[i], stdout);
        i++;
    }

    return 0;
}