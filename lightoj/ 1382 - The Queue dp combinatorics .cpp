#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 1005
#define mod 1000000007

//int dp[MX] [MX] [MX];
//int vis[MX] [MX][MX];
//int grid[MX] [MX];
ll per[MX];
int n;
vector<int> under[MX];


int tc;

ll bigMod(ll a, ll b)
{

    if(b==0)
        return 1;

    ll ret = bigMod(a, b/2);
    ret*=ret;

    if(ret>=mod)
        ret%=mod;

    if(b&1)
        ret*=a;
    if(ret>=mod)
        ret%=mod;

    return ret;

}



pair<ll, ll> rec(int u)
{
//    if(n==1)
//    return 1;
//    printf("u %d under %d\n", u, under[u].size());
    if(under[u].size()==0)
        return make_pair(1,1);
    ll ret=1;
    pair<ll,ll> p;
    ll pre=1;
    ll tot=0;
    vector<int> by;
    for(int i=0; i< under[u].size(); i++)
    {
        p = rec(under[u][i]);

        pre*= p.first;
        if(pre>=mod)
            pre%=mod;
        tot+=p.second;
        by.push_back(p.second);
//        by*= per[p.second];
//        if(by>=mod)
//            by%=mod;
    }
//    printf("u %d pre %lld tot %lld by %lld\n", u, pre, tot, by);

    ret = (pre* per[tot]);
    if(ret>=mod)
        ret%=mod;

    for(int i=0; i<by.size(); i++)
    {
        ret*= bigMod(per[by[i]], mod-2);

        if(ret>=mod)
            ret%=mod;
    }


//    under[u].clear();
//    printf("u %d pre %lld tot %lld by %lld ret %lld\n", u, pre, tot, by, ret);

    return make_pair(ret, tot+1);

}

int main()
{

//    process[0]= {1,2,3};

//    cout<<process[0].id<<" "<<process[0].at<<" "<<process[0].bt<<endl;
    int t;

    scanf("%d", &t);
//    memset(ncr, -1, sizeof ncr);
//    memset(dp, -1, sizeof dp);
    per[0]=1;
    for(int i=1; i<=1000; i++)
    {
        per[i] =i* per[i-1];
        if(per[i]>=mod)
            per[i] %=mod;
//        printf("%lld ", per[i]);
    }

    for( tc=1; tc<=t; tc++)
    {
//        int n;
        scanf("%d", &n);
        int u,v;
        bool notCEO[MX];
        for(int i=1; i<=n; i++)
        {
            notCEO[i]=false;
            under[i].clear();

        }

        for(int i=1; i<n; i++)
        {
            scanf("%d %d", &u, &v);
            under[u].push_back(v);
            notCEO[v]=1;
        }

        for(int i=1; i<=n; i++)
        {
            if(!notCEO[i])
            {
//                printf("CEO %d\n",i);
                printf("Case %d: %lld\n", tc, rec(i).first);
                break;
            }

        }

    }


    return 0;
}
