#include <stdio.h>
int main(void){
    char buf[BUFSIZ];
    FILE *fp1, *fp2;

    if(((fp1 = fopen("test1.txt", "a")) != NULL) &&
        ((fp2 = fopen("test2.txt", "w")) != NULL))
        {
            setbuf(fp1, buf);
            printf("fp1 set to user-defined buffer at:%p\n", buf);
            setbuf(fp2, NULL);
            printf("fp2 buffering disbled\n");
            fclose(fp1);
            fclose(fp2);
        }
}