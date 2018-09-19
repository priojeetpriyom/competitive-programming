#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
    int n,r,N[10010],R[10010],i,j;
    while(scanf("%d %d",&n,&r)==2) {
        for(i=0;i<r;i++) scanf("%d",&R[i]);
        if(n==r) printf("*\n");
        else {
            for(i=0;i<n;i++) N[i]=i+1;
            for(i=0;i<r;i++) N[(R[i]-1)]=0;
            for(i=0;i<n;i++) if(N[i]!=0) printf("%d ",N[i]);
            printf("\n");
        }
    }
    return 0;
}
