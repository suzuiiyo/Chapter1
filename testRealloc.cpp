#include <stdlib.h>
#include <stdio.h>

int main(){
    int *sqlist, i, len;
    len = 10;
    sqlist = (int *)malloc(len * sizeof(int));
    for (i = 0; i < 20; i++){
        if(i>=len){
            len = len * 2;
            sqlist = (int *)realloc(sqlist, len * sizeof(int));
        }
        sqlist[i] = i;
    }

    for (i = 0; i < 20; i++){
        printf("%d\n", sqlist[i]);
    }

    free(sqlist);
}