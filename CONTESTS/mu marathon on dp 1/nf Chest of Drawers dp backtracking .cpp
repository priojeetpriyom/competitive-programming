#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll dp[70] [70] [2];
int n, s;

ll rec(int drawers, int secure, int prev) {

    if(!drawers) {
        if(secure == s) return 1;
        return 0;
    }
    if(secure<s) return 0;

    ll &ret = dp[drawers] [secure] [prev];

    if(ret != -1) return ret;


    return ret = rec(drawers-1, secure-1, 1) + rec(drawers-1, secure-prev, 0);



}




int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);
    while(scanf("%d %d", &n, &s)==2 && !(n== -1&& s== -1) ) {
        memset(dp, -1, sizeof dp);
        printf("%lld\n", rec(n,n,0));
//        cout<<rec(n,n,0)<<endl;
    }


    return 0;
}
