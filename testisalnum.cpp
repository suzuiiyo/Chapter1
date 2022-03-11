#include <stdio.h>
#include <ctype.h>

int main(void){
    char c, ch;
    scanf("%c", &c);
    ch = getchar();
    while(c!='e')
    {
        if(isalnum(c))
            printf("This is a alpha or a number\n");
        else
            printf("This is a particulate character\n");

        scanf("%c", &c);
        ch = getchar();
    }
    return 1;
}