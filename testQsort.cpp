#include <stdio.h>
#include <stdlib.h>

int CMP(int *a, int *b)
{
    if(*a < *b){
        return -1;
    }
    else if(*a > *b)
        return 1;
    else
        return 0;
}

int main(void){
    int sort[10] = {3, 2, 6, 12, 17, -5, 9, 30, 16};
    int i;
    printf("\nThe array that is before sort\n");

    for (i = 0; i < 10; i++){
        printf("%d", sort[i]);
    }

    // qsort(sort, 10, sizeof(int), CMP);
    printf("\nThe array that is after sort\n");
    for (i = 0; i < 10; i++){
        printf("%d", sort[i]);
    }

    getchar();
}