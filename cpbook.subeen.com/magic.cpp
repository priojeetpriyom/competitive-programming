#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int main()
{
    int i,j,k,t,vora,uthano,last,baki,normal;
    char str[100];

    scanf("%d",&t);
    while (t--) {
        vora=0,uthano=0,j=0,last=1,k=0,normal=1,baki=0;
        scanf("%s",&str);
        for (i=0;i<strlen(str);i++) {
            if (str[i]-48 !=last) {
                k++;
                last = str[i]-48;
            }
            if(k==2) {
                if (uthano>vora+baki) {
                   printf("MAGIC\n");
                    normal=0;
                    break;
                }
                else {
                    baki+=vora-uthano;
                    vora=0;
                    uthano=0;
                    k=0;
                }
            }
            if(str[i] == 48) uthano++;
            if (str[i] == 49) vora++;
            if(i==strlen(str)-1 && (uthano>vora+baki)) {
                printf("MAGIC\n");
                normal=0;
            }
        }
        if(normal==1) printf("NORMAL\n");
    }
    return 0;
}
