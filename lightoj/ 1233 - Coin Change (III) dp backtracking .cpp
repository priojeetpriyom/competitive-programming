#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 10100

//ll dp[105][MX];
int tc;
int ara[105];
int c[105];
int cnt[100010];
int n;
//
#define mod 100000007

int vis[100010];
int xx=1;

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
        for(int i=1; i<=n; i++)
        {
            scanf("%d", &c[i]);

        }
        for(int i=1; i<=k; i++)
            vis[i]=0;
        ll ret=0;
        xx=0;
        for(int i=1; i<=n; i++)
        {
            xx++;
            vis[0]=xx;
            int used=0;
            for(int j=ara[i]; j<=k; j++)
            {
//                int temp = k;
//                temp-=ara[i];
                if(vis[j-ara[i]] && !vis[j])
                {
                    if(vis[j- ara[i]] ==xx)
                    {
                        used = cnt[j-ara[i]]+1;
                        if(used> c[i])
                            continue;
                        vis[j] = xx;
                        cnt[j] = used;
                    }
                    else
                    {
                        vis[j] = xx;
                        cnt[j] =used = 1;
                    }
                    ret++;
//                    printf("i %d j %d ret %lld\n", i, j , ret);
                }
//                if(used == c[i])
//                break;
//                ans[j] += ans[j-ara[i]];
//                if(ans[j]>1e17)
//                    ans[j]%=mod;
//                ret+= ans[i];
            }
        }

//        sort(ara+1, ara+n+1);
//        ara[n+1] = 1e9;
//        ret  = ans[k];
//        ll a = rec(1, k)%mod;
        printf("Case %d: %lld\n",tc, ret);

    }



    return 0;
}
