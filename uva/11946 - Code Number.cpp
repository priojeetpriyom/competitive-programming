#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
    int t=10,l,i;
    char message[81];
    scanf("%d",&t);
    gets(message);
    while (t--) {
        while(gets(message) != NULL) {
            l=strlen(message);
            //printf("l %d\n",l);
            if(l==0) break;
            for (i=0;i<l;i++) {
                     if(message[i]== 49) printf("I");
                else if(message[i]== 50) printf("Z");
                else if(message[i]== 51) printf("E");
                else if(message[i]== 52) printf("A");
                else if(message[i]== 53) printf("S");
                else if(message[i]== 54) printf("G");
                else if(message[i]== 55) printf("T");
                else if(message[i]== 56) printf("B");
                else if(message[i]== 57) printf("P");
                else if(message[i]== 48) printf("O");
                else printf("%c",message[i]);
            }
            printf("\n");
            }
        if(t>0) printf("\n");
    }
    return 0;
}

