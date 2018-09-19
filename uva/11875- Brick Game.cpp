#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    int i,k=1,n,ara[20],t;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        for (i=0;i<n;i++) scanf("%d",&ara[i]);
        printf("Case %d: %d\n",k++,ara[n/2]);
    }
    return 0;
}
