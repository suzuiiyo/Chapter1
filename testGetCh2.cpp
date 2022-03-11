#include <stdio.h>
int main(void)
{
    FILE *fp;
    char ch;
    fp = fopen("test.txt", "w");

    fprintf(fp, "This is a test.");
    fclose(fp);

    fp = fopen("test.txt", "r");
    fseek(fp, 0L, SEEK_SET);
    while(feof(fp) == 0){
        ch = getc(fp);
        printf("%c", ch);
    }

    fclose(fp);
    return 0;
}