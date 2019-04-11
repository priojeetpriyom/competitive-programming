#include <bits/stdc++.h>
//#define N 5
//#define ll long long
//int ara[N];
using namespace std;

int main()
{
    int n,ara[111],m;
    while(scanf("%d %d",&n, &m)==2)
    {
        for(int i=0;i<n;i++)
            scanf("%d",&ara[i]);
        sort(ara,ara+n);
        n=0;
        for(int i=0;i<m;i++)
           {
               if(n+ara[i]>=n)
                    break;
                n+=ara[i];
           }
        n= n* (-1);
           printf("%d\n",n);
    }
    return 0;
}
