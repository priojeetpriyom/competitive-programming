#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 10100

//ll dp[105][MX];
int tc, vis[105][MX];
int ara[105];
int n;
//
#define mod 100000007
//
//ll rec(int pos, int val)
//{
////    printf("pos %d val %d\n", pos, val);
//    if(!val) return 1;
//
//    if(pos>n ||val<0)
//        return 0;
//
//    ll &ret = dp[pos][val];
//    int  &v = vis[pos][val];
//    if(v==tc) return ret;
//
//    ret=0;
//    v= tc;
//    int s=0;
//    while(s<=val)
//    {
//        ret+= max(0LL, rec(pos+1, val-s));
//        s+=ara[pos];
//    }
//    if(ret>=1e15)
//        ret%=mod;
//
////        printf("s %d f %d turn %d ret %d\n", s, f,turn,  ret);
//    return ret;
//
//
//}
ll ans[10010];

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t, k;
    scanf("%d", &t);

    for(tc=1; tc<=t; tc++)
    {
        scanf("%d %d", &n, &k);

        for(int i=1; i<=n; i++)
        {
            scanf("%d", &ara[i]);

        }
        for(int i=1; i<=k; i++)
            ans[i]=0;
        ll ret=0;
        ans[0]=1;
        for(int i=1; i<=n; i++)
        {
            for(int j=ara[i]; j<=k; j++)
            {
//                int temp = k;
//                temp-=ara[i];
                ans[j] += ans[j-ara[i]];
                if(ans[j]>1e17)
                    ans[j]%=mod;
//                ret+= ans[i];
            }
        }

//        sort(ara+1, ara+n+1);
//        ara[n+1] = 1e9;
        ret  = ans[k];
//        ll a = rec(1, k)%mod;
        printf("Case %d: %lld\n",tc, ret%mod);

    }



    return 0;
}
