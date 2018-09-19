#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    int i,j=1,k,t,temp;
    char str[1000];
    scanf("%d",&t);
    gets(str);
    while (t--) {
        k=0;
        gets(str);
        for (i=0;i<strlen(str);i++) {

            if ((str[i]>96 && str[i]<112)) {
                temp=(str[i]-96);
                if(temp%3==0) k+=3;
                else k+=temp%3;
            }
            else if ((str[i]>111 && str[i]<116)) {
                temp=(str[i]-111);
                if(temp%4==0) k+=4;
                else k+= temp%4;
            }
            else if ((str[i]>115 && str[i]<119)) {
                temp=str[i]-115;
                if(temp%3==0) k+=3;
                else k+= temp%3;
            }
            else if ((str[i]>118 && str[i]<123)) {
                temp=str[i]-118;
                if(temp%4==0) k+=4;
                else k+=temp%4;
            }

            else k++;
        }
        printf("Case #%d: %d\n",j++,k);
    }
    return 0;
}
