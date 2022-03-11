#include <stdio.h>

int main(void)
{
    FILE *fp;
    char line[81];
    int result;
    fp = fopen("text.txt", "w+");
    if(fp == NULL)
        printf("The file test.txt was not opened !\n");
    else
    {
        fprintf(fp, "The fseek begins here: This is the file 'test.txt'.\n");

        result = fseek(fp, 23L, SEEK_SET);

        if(result)
            perror("Fseek failed");
        else{
            printf("File pointer is set to middle of first line.\n");
            fgets(line, 80, fp);
            printf("%s", line);
        }
        fclose(fp);
    }
    return 0;
}