#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void){
    int i;
    time_t t;
    // srand((unsigned)time(&t));
    srand(NULL);
    printf("Random numbers from 0 to 99\n");
    for (i = 0; i < 5; i++)
        printf("%d\n", rand() % 100);

    return 0;
}