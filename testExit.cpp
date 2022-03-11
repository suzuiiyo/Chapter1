#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    float a, b;
    printf("Enter a\n");
    scanf("%f", &a);
    printf("Enter b\n");
    scanf("%f", &b);

    if(b)
        printf("a/b=%f", a / b);
    else
    {
        printf("Error:Divide by 0");
        exit(0);
    }

    getchar();
    return 1;
}