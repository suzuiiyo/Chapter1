#include <string.h>
#include <stdio.h>
int main(void)
{
    FILE *fp;
    char string[] = "Viva la vida";
    fpos_t pos;

    fp = fopen("test.txt", "w+");
    fwrite(string, strlen(string), 1, fp);

    fgetpos(fp, &pos);
    printf("The file pointer is at byte %ld\n", pos);

    fseek(fp, 3, 0);

    fgetpos(fp, &pos);

    printf("The file pointer is at byte %ld\n", pos);
    fclose(fp);
    return 0;
}