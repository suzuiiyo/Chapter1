#include <stdio.h>
int main(void)
{
    FILE *fp;
    fp = fopen("test.txt", "r");
    if(fp==NULL)
        perror("Unable to open file for reading");
    return 0;
}