#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    int i,j,k,p,m,ara[110],coun;
    while(scanf("%d %d",&p,&m) == 2) {
        i=0,coun=0;
        while(i++<p) {
            for(j=0;j<m;j++) scanf("%d",&ara[j]);
            for(j=0;j<m;j++) {
                if(ara[j]==0) {
                    k=0;
                    break;
                }
                else k=1;
            }
            if(k==1) coun++;
        }
        printf("%d\n",coun);
    }
    return 0;
}
