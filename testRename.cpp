#include <stdio.h>
#include <string.h>

int main(void){
    FILE *file;
    char str[] = "大奥大奥大奥大奥大奥大奥";
    file = fopen("thisisit.txt", "w");
    fwrite(str, strlen(str), 1, file);

    if (rename("thisisit.txt", "oldname.txt") == 0)
        printf("Rename successful!!");
    else
        printf("Rename fail!!");
}