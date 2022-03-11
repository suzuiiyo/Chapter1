#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[] = "############";
    char d[] = "This is a test for memcpy function";
    printf("destination before memmove: %s      \n", d);
    void* ptr = memmove(d, s, strlen(s));
    
    if(ptr)
        printf("destination after memmove:      %s\n", d);
    else
        printf("memcpy failed\n");

    return 0;
}