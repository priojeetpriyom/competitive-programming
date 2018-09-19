#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    int i,sum;
    bool prin;
    char str[100];
    while (scanf("%s",str)==1) {
        sum=0;
        int len=strlen(str);
        str[len]= '\0';
        if(len==0) continue;
        for (i=0;i<len;i++) {
            if (str[i]>64 && str[i]<91) sum+=str[i]-38;
            else if (str[i]>96 && str[i]<123) sum+=str[i]-96;
        }
        if (sum%2==0 && sum>2) printf("It is not a prime word.\n");
        else {
            prin= true;
            int root=sqrt(sum)+2;
            for (i=3;i<root;i=i+2) {
                if (sum%i==0) {
                    printf("It is not a prime word.\n");
                    prin=false;
                    break;
                }
            }
            if(prin==true) printf("It is a prime word.\n");
        }
    }
    return 0;
}
