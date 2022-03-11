#include <stdio.h>
#include <unistd.h>

int main(void)
{
    FILE *tempfp;
    tempfp = tmpfile();
    if(tempfp)
        printf("Temporary file be created!!\n");
    else
    {
        printf("Unable to create the temporary file!\n");
        _exit(1);
    }
    sleep(20);
    return 0;
}