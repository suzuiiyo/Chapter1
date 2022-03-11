#include <stdio.h>
#include <stdlib.h>

int CMP(int *a, int *b)
{
    if(*a < *b)
        return -1;
    else if(*a> *b)
        return 1;
    else
        return 0;
}

int main(void)
{
    int search[10] = {1, 3, 6, 7, 10, 11, 13, 19, 28, 56};
    int a = 13, *p, i;
    // p = (int *)bsearch(&a, search, 10, sizeof(int), CMP);
    printf("The elems of the array are\n");
    for (int i = 0; i < 10; i++){
        printf("%d", search[i]);
    }

    if(p)
        printf("\nThe elem 13 is located at %d of the array\n", p - search + 1);
    else
        printf("    \n");
    getchar();
}