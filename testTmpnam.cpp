#include <string.h>
#include <stdio.h>

int main(){
    char tmp[10];
    tmpnam(tmp);
    printf("The temporary name is %s\n", tmp);
    return 0;
}