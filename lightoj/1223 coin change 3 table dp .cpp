#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

//------------ loop macros

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define fr(i,start, till) for(int i=start; i<=till; i++)
#define frr(i,start, till) for(int i=start; i>=till; i--)


//-------------- input macros

#define cin0(n, ara) for(int i=0; i<n; i++) {cin>>ara[i];}
#define cini0(i, n, ara) for(int i=0; i<n; i++) {cin>>ara[i];}

#define cin1(n, ara) for(int i=1; i<=n; i++) {cin>>ar[i];}
#define cini1(i, n, ara) for(int i=1; i<=n; i++) {cin>>ar[i];}


#define si(n) scanf("%d", &n);
#define sii(n, m) scanf("%d %d", &n, &m);
#define siii(n, m, k) scanf("%d %d %d", &n, &m, &k);
#define siiii(n, m, k, o) scanf("%d %d %d %d", &n, &m, &k, &o);

#define sl(n) scanf("%lld", &n);
#define sll(n, m) scanf("%lld %lld", &n, &m);
#define slll(n, m, k) scanf("%lld %lld %lld", &n, &m, &k);
#define sllll(n, m, k, o) scanf("%lld %lld %lld %lld", &n, &m, &k, &o);

#define sd(n) scanf("%lf", &n);
#define sdd(n, m) scanf("%lf %lf", &n, &m);
#define sddd(n, m, k) scanf("%lf %lf %lf", &n, &m, &k);
#define sdddd(n, m, k, o) scanf("%lf %lf %lf %lf", &n, &m, &k, &o);

#define sid(n, m) scanf("%d %lf", &n, &m);


#define scs(s) scanf("\n%s", s);
#define scss(s, ss) scanf("\n%s \n%s", s, ss);


//--------------output----------

#define pr printf
#define pri(n) printf("%d\n", n);
#define prl(n) printf("%lld\n", n);
#define prll(n, m) printf("%lld %lld\n", n, m);
#define prd(n) printf("%.10lf\n", n);
#define prs(str) printf("%s\n", str);

// ------------- BIT MANIPULATION ------------

#define CHECK(n, pos) ( (n& (1LL<<pos))>0)
#define SET(n,pos) (n | (1<<pos))
#define RESET(n,pos) (n ^ (1<<pos))
#define mem(ara, val) memset(ara, val, sizeof ara);



//--------data structures
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define pdi pair<double, int>
#define pdl pair<double, ll>
#define pid pair<int, double>
#define pld pair<ll, double>

//--------others
#define SET_TIMER double timer =(double) clock();
#define PRINT_TIMER cout<<(clock()- timer)/CLOCKS_PER_SEC<<endl;
#define PRINT_LOJ_TC printf("Case %d: ", tc);
#define pb push_back
#define mp make_pair
#define log2ceil(n) ( (ll) ceil(log2(n)))
#define pow2(n) (1<<n)



#define MX 333
#define double long double
#define mod 1000000007
#define mod2 1000000009


//ll arr[MX];
//ll ara[MX];
//bool converted[MX];


//bool hasNeg;



//ll dp[MX] [1011];

//ll rec(int val, int cnt, int & l , int &r) {
//    if(!val)
//        return cnt>=l;
//    if(val<0 || cnt<l)
//        return 0;
//    ll &ret = dp[val] [cnt];
//    if(~ret)
//        return ret;
//
//    ret=0;
//    for1(i, val)
//        ret+= rec(val-i, cnt-1, l, r);
//    cout<<"val "<<val <<" cnt "<<cnt<<" ret "<<ret<<endl;
//    return ret;
//}


ll dp [100005];
int coins[105], cnt[105], vis[100005];

//int ara[105], n;

//map<int, int> mapp;

ll rec(int pos,int l, int r) {

//    cout<<"pos "<<pos<<" l "<<l<<" r "<<r<<endl;
//    assert(cnt>=0);
//    if(pos == n)
//        return 0;
//
//    ll &ret = dp[pos] [l] [r];
////    int &vis = visited[amount] [pos];
//    if(~ret) return ret;
////    vis = tc;
//    ret=0;
//
//    if(ara[pos]>=l && r==0) {
//        ret = max(ret, rec(pos+1, ara[pos], r)+1);
//    }
//
//    if(r==0 && ara[pos]>=l) {
//        ret = max(ret, rec(pos+1, l, ara[pos])+1);
////        if(ara[pos]>l) {
////            ret = max(ret, rec(pos+1, l, ara[pos])+1);
////        } else {
////            ret = max(ret, rec(pos+1, ara[pos], l)+1);
////        }
//    }
//    {
//        if(ara[pos]>=l && ara[pos]<=r) {
//            ret = max(ret, rec(pos+1, ara[pos], r)+1);
//            ret = max(ret, rec(pos+1, l, ara[pos])+1);
//        }
//    }
//    ret = max(ret, rec(pos+1, l, r));
//
////    ret+= rec(amount, pos+1);
//
//
//    return ret;


}


int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    freopen("input.txt", "w", stdout);

//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

//    SET_TIMER


    int t;
    si(t);

    for1(tc, t) {
        int n, m;
        sii(n,m);
        for1(i, n)
            si(coins[i]);
        for1(i, n)
            si(cnt[i]);
        mem(vis, 0);

//        for1(i, n)
//            dp[0][i]=1;
        vis[0]=1;
        int ans=0;
        for1(i, n) {
//            mem(dp, 0)
            for0(j, coins[i])
                dp[j]=0;
            fr(val,coins[i], m) {
//                if(val<coins[i])
//                    continue;
                if(!vis[val] && vis[val- coins[i]] && dp[val- coins[i]] +1<= cnt[i]) {
                    vis[val]=1;
                    ans++;
                    dp[val] = dp[val-coins[i]]+1;
                } else
                    dp[val]=0;
            }
        }

        PRINT_LOJ_TC
        pri(ans)


    }



//    PRINT_TIMER
}
