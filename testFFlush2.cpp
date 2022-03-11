#include <string.h>
#include <stdio.h>
// #include <conio.h>
// #include <io.h>

int main(void){
    FILE *stream1, *stream2;
    char test[20] = "This is a test";
    char res[20];
    stream1 = fopen("test.txt", "w");

    fwrite(test, 15, 1, stream1);
    fflush(stream1);
    stream2 = fopen("test.txt", "r");

    if(fread(res, 15, 1, stream2)){
        printf("%s", res);
    }else{
        printf("Read error!\n");
    }

    fclose(stream1);
    fclose(stream2);
    // getch();
    return 0;
}