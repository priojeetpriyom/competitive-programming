 #include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
    int n,i,t,root,k=1,b;
    scanf("%d",&t);
    while(t--) {
        b=0;
        scanf("%d",&n);
        root=sqrt(n)+1;
        printf("Case #%d: %d",k++,n);
        for(i=2;i<root;i++) {
            if(n%i==0 && i!=(n/i)) {
                b++;
                printf(" = %d * %d",i,(n/i));
            }
            if(b==2) break;
        }
        printf("\n");
    }
    return 0;
}
