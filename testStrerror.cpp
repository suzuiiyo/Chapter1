#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char*argv[])
{
    printf("%s\n", argv[0]);

    char *error;
    int i;
    for (i = 0; i < 12; i++){
        error = strerror(i);
        printf("%s\n", error);
        // perror(argv[0]);
    }
    getchar();
    return 0;
}