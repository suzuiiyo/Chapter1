#include <string.h>
#include <stdio.h>

int main(void){
    char const *str = "I love China\n";
    void* p = memchr(str, 'C', strlen(str));
    if(p)
        printf("%s", p);
    else
        printf("The character was not found\n");
}