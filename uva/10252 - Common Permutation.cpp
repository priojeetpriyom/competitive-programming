#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    int i,j,k,l1,l2,m,n;
    char str1[1100],str2[1100],str3[1100];
    while(gets(str1)&&gets(str2)) {

        n=0;
        l1=strlen(str1),l2=strlen(str2);
        for(i=0;i<l1;i++) {
            for(j=0;j<l2;j++) {
                if(str1[i] == str2[j]) {
                    str3[n++]=str1[i];
                    //printf("%c %c\n",str2[j],str3[n-1]);
                    str2[j]=32;
                    break;
                    }
                }
            }
        //printf("%s\n",str3);
        str3[n]='\0';
        if(strlen(str3)>1)
        for(i=0;i<strlen(str3);i++) for(j=i;j<strlen(str3);j++) if(str3[i]-str3[j]>0) swap(str3[i],str3[j]);
        printf("%s\n",str3);
        //memset(str3,0,strlen(str3));
        }
    return 0;
}
