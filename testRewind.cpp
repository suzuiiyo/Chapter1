#include <stdio.h>

int main(void)
{
    FILE *fp;
    int data1, data2;

    data1 = 1;
    data2 = 2;
    if((fp = fopen("test.txt", "w+")) != NULL)
    {
        fprintf(fp, "%d %d", data1, data2);
        printf("The values written are:%d and %d\n", data1, data2);
        data1 = 0;
        data2 = 0;
        rewind(fp);
        fscanf(fp, "%d %d", &data1, &data2);
        printf("The values read are: %d  and %d\n", data1, data2);
        fclose(fp);
    }
}