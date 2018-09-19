#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    int n,k,p,t,j=1;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d %d",&n,&k,&p);
        if (p<n) k+=p;
        else if(k+=p%n) ;
        if(k<=n) printf("Case %d: %d\n",j++,k);
        else printf("Case %d: %d\n",j++,k-n);
    }
    return 0;
}
