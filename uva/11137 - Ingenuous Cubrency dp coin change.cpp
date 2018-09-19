#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll coins[22], dp[10000+5] [22];

ll rec(int pos, int val) {
    if(!val)
        return 1;
    if(val<0 || pos>21)
        return 0;

    ll &ret = dp[val] [pos];

    if(ret != -1) return ret;

    return ret = rec(pos, val- coins[pos]) + rec(pos+1, val);
}


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    memset(dp, -1, sizeof dp);
    for(int i=1; i<=21; i++)
        coins[i] = i*i*i;

    for(int i=1; i<=10000; i++)
        rec(1, i);

    int n;

    while(scanf("%d", &n)==1)
    {
        printf("%lld\n", dp[n][1]);
    }

    return 0;
}



