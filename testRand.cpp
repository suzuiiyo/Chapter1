#include <stdlib.h>
#include <stdio.h>

int main(void){
    int i;
    printf("Random numbers from 0 to 99\n");
    for (i = 0; i < 5; i++){
        printf("%d \n", rand() % 100);
    }

    return 0;
}