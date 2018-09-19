#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 51

ll dp[MX][MX][MX];
//int vis[MX][MX][MX][MX];
//int ara[105];


//#define mod 10056
int n, m ,k;
int tc;

ll rec(int remaining, int groups)
{
    if(groups<0 || remaining<0 || groups>remaining)
        return 0;
    if(!remaining && !groups)
    return 1;
    if(!remaining)
        return 0;

//    printf("pos %d val %d\n", pos, val);
//    if(pos>len) return 0;

//    if(pos>n  || ara[pos]>val)
//        return -1e9;

    ll &ret = dp[remaining] [groups]  [m];
//    int  &v = vis[pos][val];
//    if(vis[remaining] [groups] [same] [m] == tc) return ret;
    if(~ret) return ret;
//    vis[remaining] [groups] [same] [m] = tc;
//    ret=1e9;
    ret=0;
//    v= tc;

//    ret = rec(remaining-1, groups, same-1) + ( (same==m)?0: rec(remaining-1, groups-1, m-1));
    for(int i=1; i<=m; i++)
        ret += rec(remaining-i, groups-1);
//        ret+= (  rec(remaining-1, groups-1, m-1));
//        ret = rec(remaining-1, groups, same-1) + (  rec(remaining-1, groups-1, m-1));
//    if(ret>=mod)
//        ret%=mod;

//        printf("s %d f %d turn %d ret %d\n", s, f,turn,  ret);
    return ret;


}


int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    rec(1,1);
    memset(dp, -1, sizeof dp);
    int t;
    scanf("%d", &t);
    for( tc=1; tc<=t; tc++)
    {
        scanf("%d %d %d", &n, &k, &m);
//        memset(dp, -1, sizeof dp);
        printf("Case %d: %lld\n",tc, rec(n, k));

    }



    return 0;
}

