#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int main()
{
    int i,len,k=0;
    char str[10000];
    while (gets(str)) {
        len=strlen(str);
        for (i=0;i<len;i++) {
            if (str[i] =='"') {
                k++;
                if (k&1==1) {
                    printf("``");
        }
                else{
                    printf("''");
        }
        }
            else printf("%c",str[i]);
        }
        printf("\n");
    }
    return 0;
}
