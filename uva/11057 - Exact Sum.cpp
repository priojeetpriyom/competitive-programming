#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
int main() {
    int t,n,i,j,k,m,j1,i1,diff;
    int ara[11000];
    while (scanf("%d",&n)!= EOF) {
        for (i=0;i<n;i++) scanf("%d",&ara[i]);
            scanf("%d",&m);
            diff=m;
            sort(ara,ara+n);
        for (i=0;i<n-1;i++) {
            for (j=i+1;j<n;j++) {
                if ((ara[i]+ara[j])==m ) if ((ara[i]<=ara[j])) if (ara[j]-ara[i]<diff) {
                    diff=ara[j]-ara[i];
                    j1=ara[j];
                    i1=ara[i];
                }
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n",i1,j1);
    }
    return 0;
}
