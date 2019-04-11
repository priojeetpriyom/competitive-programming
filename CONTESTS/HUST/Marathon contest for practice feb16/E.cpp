#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y, k, n;
    while(scanf("%d %d %d",&y, &k, &n)==3) {
        if(y>= n)
            printf("-1\n");
        else
        {
            x= y- (y%k);
            while(x<=y)
                x+=k;
            if(x>n)
            {
                printf("-1\n");
                continue;
            }
            for(; x<=n; x+=k)
                printf("%d ",x-y);
            printf("\n");
        }
    }
    return 0;
}
