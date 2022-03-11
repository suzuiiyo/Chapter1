#include <stdio.h>

int main(void)
{
    char str[] = "1 2 3...";
    char s[81];
    char c;
    int i;
    float fp;

    sscanf(str, "%s", s);
    sscanf(str, "%c", &c);
    sscanf(str, "%d", &i);
    sscanf(str, "%f", &fp);

    printf("String =%s\n", s);
    printf("Character = %c\n", c);
    printf("Integer = %d\n", i);
    printf("Real: =%f\n", fp);

    return 0;
}