#include <string.h>
#include <stdio.h>

int main(void)
{
    FILE *fp;
    char string[] = "This is a test";
    char str[20];

    fp = fopen("test.txt", "w+");
    fwrite(string, strlen(string), 1, fp);

    fseek(fp, 0, SEEK_SET);
    fgets(str, strlen(string) + 1, fp);

    printf("%s", str);
    fclose(fp);

    return 0;
}