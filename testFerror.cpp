#include <stdio.h>
int main(void){
    FILE *fp;
    char ch;
    fp = fopen("test.txt", "w");
    ch = fgetc(fp);
    printf("%c\n", ch);

    if(ferror(fp))
    {
        printf("Error reading from test.txt!\n");
        clearerr(fp);
    }

    fclose(fp);
    return 0;
}