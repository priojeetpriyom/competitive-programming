#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    int t,n,jump[1000],high,low,i,k=1,j;
    scanf("%d",&t);
    while (t--) {
        high=0,low=0;
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",&jump[i]);
        for(i=0,j=1;j<n;i++,j++) {
            if(jump[j] > jump[i]) high++;
            else if (jump[j] < jump[i]) low++;
        }
        printf("Case %d: %d %d\n",k++,high,low);
    }
    return 0;
}
