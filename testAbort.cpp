#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Calling abort()\n");
    abort();
    printf("Is the program be held?\n");
    return 0;
}