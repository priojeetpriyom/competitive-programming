#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, l1,l0,r1,r0,l,r;
    while(scanf("%d",&n)==1) {
        l1=0,l0=0,r1=0,r0=0;
        while(n--)
        {
            scanf("%d %d",&l, &r);
            if(l==0)
                l0++;
            else
                l1++;
            if(r==0)
                r0++;
            else
                r1++;
        }
        printf("%d\n",min(l0,l1)+min(r0,r1));
    }
    return 0;
}
