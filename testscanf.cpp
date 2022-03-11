#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    char ch;
    printf("Please input an character:");

    if(fscanf(stdin, "%c", &ch)){
        printf("The character was:%c\n", ch);
    }
    else
    {
        fprintf(stderr, "Error reading an character from stdin!!\n");
        exit(1);
    }
    return 0;
}