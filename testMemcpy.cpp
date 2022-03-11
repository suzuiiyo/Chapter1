#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[] = "###########";
    char d[] = "This is a test for memcpy function";

    printf("destination before memcpy:%s    \n", d);
    void* ptr = memcpy(d, s, strlen(s));
    if(ptr)
        printf("destination after memcpy: %s\n", d);
    else
        printf("memcpy failed\n");

    return 0;
}