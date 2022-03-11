#include    <string.h>
#include    <stdio.h>

int main(void)
{
    char d[] = "12345667890";
    char *p;
    p = d + 3;
    printf("d = %s\n", d);
    printf("p = %s\n", p);
    memmove(p, d, 6);
    printf("%s\n", d);

    return 0;
}
