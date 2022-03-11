#include <stdlib.h>
#include <stdio.h>

int main(void){
    char *s;
    s = getenv("JAVA_HOME");
    printf("Command processor: %s\n", s);

    return 0;
}