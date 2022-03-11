#include <stdio.h>

int main(void)
{
    FILE *fp1, *fp2;

    if((fp1 = fopen("text.txt", "rt")) == NULL)
    {
        fp2 = fopen("report.txt", "w");
        fprintf(fp2, "Cannot open this file!!\n");
        return 1;
    }

    return 0;
}