#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
int main() {
    int t,num,i,l,m,a,r,g,I,T;
    char marga[1000];
    scanf("%d",&t);
    while (t--) {
        m=a=r=g=I=T=0;
        num=110;
        scanf("%s",&marga);
        l=strlen(marga);
        for (i=0;i<l;i++) {
            if(marga[i]== 'M') m++;
            else if(marga[i]== 'A') a++;
            else if(marga[i]== 'R') r++;
            else if(marga[i]== 'G') g++;
            else if(marga[i]== 'I') I++;
            else if(marga[i]== 'T') T++;
        }
        a=a/3;
        r/=2;
        if(m<num) num=m;
        if(a<num) num=a;
        if(r<num) num=r;
        if(g<num) num=g;
        if(I<num) num=I;
        if(T<num) num=T;
        printf("%d\n",num);

    }
    return 0;
}
