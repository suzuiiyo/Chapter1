#include <stdio.h>
int main(void)
{
    FILE *fp;
    fp = fopen("test.txt", "w+");
    fprintf(fp, "This is a test");
    printf("The file pointer is at byte %ld\n", ftell(fp));

    fclose(fp);
    return 0;
}