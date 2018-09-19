#include <iostream>
#include <cstdio>
#include <string.h>
int main ()
{
    char str[1000];
    int i;
    while (gets(str)) {
    for (i=0; i< strlen(str); i++) {
        printf("%c",str[i] - 7);
    }
    }
   return 0;
}
