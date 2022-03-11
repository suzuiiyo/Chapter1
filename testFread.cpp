#include <string.h>
#include <stdio.h>

int main(void)
{
    FILE *fp;
    char str[] = "this is a test";
    char buf[20];

    if((fp = fopen("test.txt", "w+")) == NULL)
    {
        fprintf(stderr, "Cannot open output file!!\n");
        return 1;
    }

    fwrite(str, strlen(str), 1, fp);

    fseek(fp, SEEK_SET, 0);
    fread(buf, strlen(str), 1, fp);
    printf("%s\n", buf);
    fclose(fp);

    return 0;
}