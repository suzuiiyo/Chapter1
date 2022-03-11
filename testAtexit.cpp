#include <stdio.h>
#include <stdlib.h>

void fun1(void){
    printf("Exit function #1 called\n");
}

void fun2(void)
{
    printf("Exit function #2 called\n");
}

int main(void){
    // atexit(fun1);
    // atexit(fun2);
    fun1();
    fun2();
    return 0;
}