#include <stdio.h>
#include <string.h>

int main(void)
{
    int a = 1;
    char ch = 'r';
    char str[] = "This is a test!";
    printf("Output a string.\n");
    printf("%s", str);
    printf("The integer is %d\n", a);
    printf("The character is %c\n", ch);

    return 0;
}