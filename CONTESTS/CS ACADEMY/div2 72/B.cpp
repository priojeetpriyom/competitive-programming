#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 5050

ll ara[MX];


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin>>n;

    for(int i=2; i<=n; i++)
        cin>>ara[i];

    cin>>ara[1];

    for(int i=1; i<=n; i++)
        ara[i]+= ara[i-1];

    int mn_val=1e9, mn_id=1;

//    for(int i=1; i<=n; i++)
//        printf("%d ", ara[i]);
    for(int i=1; i<=n; i++)
    {
        int mx=0;
        for(int j=1; j<=n; j++)
        {
            if(i!=j)
            {
                int dist;
                if(i<j)
                {
                    dist = min(ara[j] - ara[i], ara[i] + (ara[n] - ara[j]));
                }
                else
                {
                    dist = min(ara[i]-ara[j], ara[n]-ara[i]+ara[j]);
                }
                if(dist>mx)
                {
                    mx = dist;
                }
            }
        }
        if(mx<mn_val)
        {
            mn_val = mx;
            mn_id = i;
        }
//        printf("i %d mx %d\n", i, mx);

    }

    cout<<mn_id<<endl;

    return 0;
}


