#include <bits/stdc++.h>
using namespace std;

int main()
{
    int mx=INT_MIN;
    int n,k,f,t;
    while(scanf("%d %d",&n,&k)==2)
    {
        mx=INT_MIN;
        while(n--)
        {
            scanf("%d %d",&f,&t);
            if(t>k)
            {
                 f= f - (t-k);
                 if(f>mx)
                    mx=f;
            }
            else if(f>mx)
                mx=f;
        }
        printf("%d\n",mx);
    }
    return 0;
}
