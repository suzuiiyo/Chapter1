#include <string.h>
#include <stdio.h>

int main(void)
{
    FILE *fp;
    char buf[11] = "abcdefghij";
    fp = fopen("test.txt", "w");

    fwrite(&buf, strlen(buf), 1, fp);

    fclose(fp);
    return 0;
}