#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,ara[105],a,b;
    while(scanf("%d",&n)==1)
    {
        ara[0]= INT_MAX;
        int mn=INT_MAX;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&ara[i]);
            if(abs(ara[i]-ara[i-1]) < mn)
            {
                   mn= abs(ara[i]-ara[i-1]);
                   a=i;
                   b=i-1;
            }
        }
        if(abs(ara[n]-ara[1]) < mn)
        {
            mn= abs(ara[n]-ara[1]);
            a=n;
            b=1;
        }
        printf("%d %d\n",a,b);
    }

    return 0;
}
