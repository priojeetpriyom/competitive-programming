#include <iostream>
#include <cstdio>
#include <string.h>
int main ()
{
    int t,ara[100000],n,i,maxx,j=1;
    scanf("%d",&t);
    while (t--) {
        maxx=0;
        scanf("%d",&n);
        for (i=0;i<n; i++) {
            scanf("%d",&ara[i]);
        }
        for (i=0;i<n; i++) if(ara[i] > maxx) maxx = ara[i];
        printf("Case %d: %d\n",j++,maxx);
    }
   return 0;
}

