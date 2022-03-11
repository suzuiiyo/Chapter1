#include <stdio.h>
#include <ctype.h>


int main(void)
{
    char c, ch;
    scanf("%c", &c);
    ch = getchar();
    while(c!='e'){
        if(isalpha(c))
            printf("This is a alpha\n");
        else{
            printf("This is not a alpha\n");
        }
        scanf("%c", &c);
        ch = getchar();
    }
    return 1;
}