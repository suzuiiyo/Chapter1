#include <time.h>
#include <stdio.h>

int main(void){
    clock_t start, end;
    start = clock();
    // delay(1000);
    end = clock();
    // printf("The time was :%f\n", (end - start) / CLK_TCK);

    return 0;
}