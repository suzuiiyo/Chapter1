#include <stdio.h>
int main(void){
    FILE *fp;
    fpos_t pos;
    char buffer[50];
    if((fp = fopen("test.txt", "rb")) == NULL){
        printf("Trouble opening file\n");
    }
    else
    {
        // pos = 10;
        // if (fsetpos(fp, &pos) != 0)
        // {
        //     perror("fsetpos error");
        // }
        // else{
        //     fread(buffer, sizeof(char), 16, fp);
        //     printf("16 bytes at byte %ld: %.16s \n", pos, buffer);
        // }
    }
}