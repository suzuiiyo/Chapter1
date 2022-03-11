#include <stdio.h>

int main(void)
{
    FILE *Nfp;

    if((Nfp=freopen("test.txt", "w", stdout)) == NULL){
        fprintf(stderr, "error redirecting stdout\n");
    }
    printf("This will go into a file");

    fclose(stdout);
    fclose(Nfp);
    return 0;
}