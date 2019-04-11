#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long clockWise=0;
    int n,x;
    char c;
    while(scanf("%d", &n)==1)
    {
        while(n--)
        {
            scanf("%d \nc", &x, &c);
            if(c == 'C')
                clockWise+= x;
            else
                clockWise-=x;
        }
        printf("%lld\n",min(abs(clockWise),180-abs(clockWise)));
    }
    return 0;
}
