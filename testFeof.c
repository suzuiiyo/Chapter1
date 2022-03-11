#include <stdio.h>
int main(void)
{
    FILE *stream;
    stream = fopen("test.txt", "r");
    int i = fgetc(stream);

    printf("i=%c\n", i);
    int j = fseek(stream, 15, 2);
    printf("j=%d\n", j);
    printf("%d\n", feof(stream));
    if (feof(stream))
        printf("Have reached the end of the file!\n");

    fclose(stream);
    return 0;
}