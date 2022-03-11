#include <stdio.h>

int main(void)
{
    int i;
    char ch;
    float f;
    printf("please input an integer:\n");
    scanf("%d", &i);

    getchar();
    printf("Please input a character:\n");
    scanf("%c", &ch);
    getchar();
    printf("Please input an float:\n");
    scanf("%f", &f);
    getchar();
    printf("These values are: %d, %c, %f", i, ch, f);

    return 0;
}