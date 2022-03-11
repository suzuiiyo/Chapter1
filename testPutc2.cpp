#include <stdio.h>

int main(void)
{
    FILE *fp;
    int i = 0;
    char str[] = "This is a test!";
    fp = fopen("test.txt", "w");
    while(str[i]){
        putc(str[i], fp);
        i++;
    }
    fclose(fp);

    return 0;
}