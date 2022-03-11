#include <stdio.h>

int main(void)
{
    FILE *fp;
    char ch;
    fp = fopen("test.txt", "w");
    ch = fgetc(fp);
    if(ferror(fp))
    {
        printf("This is a error reading!\n");
        clearerr(fp);
    }else{
        printf("%c\n", ch);
    }
    
    fclose(fp);
        return 0;
}