#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

//#include <stdio.h>
//#include <string.h>
//#define ll long long

ll dp[1111], vis[1111], ara[1111];
int n, tc;

ll rec(int pos) {

    if(pos>=n) return 0;
    ll &ret  = dp[pos];
    if(vis[pos] == tc) return ret;
    vis[pos] = tc;

    return ret = max( rec(pos+2)+ara[pos], rec(pos+1) );

}



int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    int t;
    scanf("%d", &t);

    for(tc=1; tc<=t; tc++) {
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%lld", &ara[i]);
        }

        printf("Case %d: %lld\n",tc, rec(0));
    }

    return 0;
}
