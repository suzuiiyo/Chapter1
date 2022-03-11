#include <stdio.h>

int main()
{
    char str[] = "This is a test!\n";
    int i = 0;
    while(str[i]){
        putchar(str[i]);
        i++;
    }
}