#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    int i,j,k,sum1;
    float div1,div2;
    char str1[50],str2[50];
    while(gets(str1) && gets(str2)) {
        sum1=0;
        for (i=0;i<strlen(str1);i++) {
            if ((str1[i]>64 && str1[i]<91)) {
                sum1+=str1[i]-64;
            }
            else if ((str1[i]>96 && str1[i]<123)) {
                sum1+=str1[i]-96;
            }

        }

        div1=0;
        if(sum1>9) {
            while (1) {
                while(sum1>0) {
                    div1+=sum1%10;
                    sum1/=10;
                }
                if(div1>9) {
                    sum1=div1;
                    div1=0;
                }
                else break;
        }
        }
        else div1=sum1;

        sum1=0;
        for (i=0;i<strlen(str2);i++) {
            if ((str2[i]>64 && str2[i]<91)) {
                sum1+=str2[i]-64;
            }
            else if ((str2[i]>96 && str2[i]<123)) {
                sum1+=str2[i]-96;
            }
        }
        div2=0;
        if(sum1>9) {
            while (1) {
                while(sum1>0) {
                    div2+=sum1%10;
                    sum1/=10;
                }
                if(div2>9) {
                    sum1=div2;
                    div2=0;
                }
                else break;
        }
        }
        else div2=sum1;
        if (div1>div2) printf("%.2f %%\n",(div2/div1)*100);
        else printf("%.2f %%\n",(div1/div2)*100);
    }
    return 0;
}
