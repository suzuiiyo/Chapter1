#include <stdio.h>

int main(){
    if(remove("text.txt") == -1)
        perror("Could not delete test.txt!!");
    else
        printf("Deleted test.txt\n");

    return 0;
}