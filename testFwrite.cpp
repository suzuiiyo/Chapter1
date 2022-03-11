#include <stdio.h>

struct exp_struct
{
    int i;
    char ch;
};

int main(void){
    FILE *fp;
    struct exp_struct s;
    if ((fp = fopen("test.txt", "wb")) == NULL)
    {
        fprintf(stderr, "Cannot open the test.txt");
        return 1;
    }

    s.i = 0;
    s.ch = 'A';
    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);

    return 0;
}