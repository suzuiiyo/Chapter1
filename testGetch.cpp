#include <string.h>
#include <stdio.h>
// #include <conio.h>

int main(void)
{
    FILE *fp;
    char string[] = "This is a test";
    char ch;

    fp = fopen("test.txt", "w+");

    fwrite(string, strlen(string), 1, fp);

    fseek(fp, 0, SEEK_SET);
    int i = 0;
    do
    {
        ch = fgetc(fp);
        // printf("%d\n", i);
        i++;
        printf("%c\n", ch);
    } while (ch != EOF);
    fclose(fp);
    return 0;
}