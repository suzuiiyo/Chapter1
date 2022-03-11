#include <stdio.h>
#include <string.h>

int main(void)
{
    char const *str1 = "ABCDEFG";
    char const *str2 = "ABCDEf";
    int s1, s2;
    s1 = memcmp(str1, str2, 6);
    s2 = memcmp(str1, str2, 5);

    printf("The comparision of 6 character\n");
    if(s1>0)
        printf("%s>%s\n", str1, str2);
    else
        if(s1<0)
            printf("%s<%s\n", str1, str2);
    else
        printf("%s=%s\n", str1, str2);

    printf("The comparision of 5 character\n");

    if(s2>0)
        printf("%s>%s\n", str1, str2);
    else
        if(s2<0)
            printf("%s<%s\n", str1, str2);
    else
        printf("%s=%s\n", str1, str2);
}