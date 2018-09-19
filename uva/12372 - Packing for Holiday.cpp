#include <iostream>
#include <cstdio>
#include <string.h>
int main ()
{
    int l,h,w,t,i=1;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d %d",&l,&h,&w);
        if(l<21 && h<21 && w<21) printf("Case %d: good\n",i++);
        else printf("Case %d: bad\n",i++);
    }
   return 0;
}
