#include <stdio.h>

int main(void)
{
    FILE *fp;
    char str[] = "This is a test!";

    fp = fopen("test.txt", "w");
    fputs(str, fp);

    fclose(fp);
    return 0;
}