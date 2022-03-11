#include <stdio.h>
int main(void)
{
    char str[] = "This is a test";
    int i = 0;

    while(str[i])
    {
        fputc(str[i], stdout);
        i++;
    }
    return 0;
}