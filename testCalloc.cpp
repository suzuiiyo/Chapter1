#include <stdlib.h>
#include <stdio.h>

int main(){
    int i, j, *p = NULL;
    printf("Please enter the size for allocation\n");
    scanf("%d", &i);
    p = (int *)calloc(i, sizeof(int));
    if(p)
    {
        printf("Please enter %d datas\n", i);
        for (j = 0; j < i; j++){
            scanf("%d", &p[j]);
        }
    }
    else{
        printf("Allocation is fail\n");
        return 0;
    }

    printf("The datas are\n");
    for (j = 0; j < i; j++){
        printf("%d\n", p[j]);
    }
}