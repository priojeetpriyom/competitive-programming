#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
    int i,j,coun,n,ara[1010];
    while(scanf("%d",&n)!=EOF) {
        coun=0;
        for(i=0;i<n;i++) scanf("%d",&ara[i]);
        for(i=0;i<n-1;i++) for(j=i+1;j<n;j++) if(ara[i]>ara[j]) coun++;
        printf("Minimum exchange operations : %d\n",coun);
        //memset(ara,0,sizeof(ara));
    }
    return 0;
}
