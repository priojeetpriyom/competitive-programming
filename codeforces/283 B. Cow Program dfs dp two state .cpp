#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

//------------ loop macros

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define fr(i,start, till) for(int i=start; i<=till; i++)


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

#define sid(n, m) scanf("%d %lf", &n, &m);


#define scs(s) scanf("\n%s", s)
#define scss(s, ss) scanf("\n%s \n%s", s, ss)


//--------------output----------

#define pr printf
#define pri(n) printf("%d\n", n);
#define prl(n) printf("%lld\n", n);
#define prll(n, m) printf("%lld %lld\n", n, m);

// ------------- BIT MANIPULATION ------------

#define CHECK(n, pos) ( (n& (1<<pos))>0)
#define SET(n,pos) (n | (1<<pos))
#define RESET(n,pos) (n ^ (1<<pos))
#define mem(ara, val) memset(ara, val, sizeof ara);



//--------data structures
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdi pair<double, int>
#define pdl pair<double, ll>
#define pid pair<int, double>
#define pld pair<ll, double>

//--------others
#define SET_TIMER double timer =(double) clock();
#define PRINT_TIMER cout<<(clock()- timer)/CLOCKS_PER_SEC<<endl;





#define MX 200100
#define double long double
#define mod 1000000007
#define mod2 1000000009

int ara[MX];
ll dp[MX] [5];
int vis[MX] [5];
int n;

ll rec(ll u, int dir, const int & tc) {
//    cout<<"u "<<u<<" dir "<<dir<<endl;
    if(u<=0 || u>n)
        return 0;
    if(vis[u][dir])
        return -1;


    ll &ret = dp[u][dir];
    if(ret!= -100)
        return ret;

    vis[u][dir]=1;
//    re
//    cout<<"crossed checks"<<endl;
    if(!dir) {
        ll rec_ret = rec(u - ara[u], dir^1, tc);
        ret = (rec_ret==-1)? -1 : rec_ret + ara[u];
    } else {
        ll rec_ret = rec(u + ara[u], dir^1, tc);
        ret = (rec_ret==-1)? -1 : rec_ret + ara[u];
    }
    vis[u][dir]=0;
    return ret;

}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    freopen("input.txt", "w", stdout);


//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    SET_TIMER

//    cout<<5000<<" "<<5000<<endl;
//
//    for1(i, 5000) {
//        for1(j, 5000)
//            cout<<1<<" ";
//        cout<<endl;
//    }
//    exit(0);
//    mem(dp, -1);
//    int n, m;

    si(n);

    fr(i, 2, n)
        si(ara[i]);

    for0(i, 2e5+1)
        for0(j, 3)
            dp[i][j] = -100;
//    mem(dp, -1);
    int tc=1;
    for1(i, n-1) {
//        mem(vis, 0);
        vis[1][1]=1;
        ara[1] = i;
        ll ans = rec(i+1, 0, ++tc);

        ans = (ans==-1)? ans : ans+i;

//        cout<<"i "<<i<<" y "<<ans<<endl;
       prl(ans);
    }

//    PRINT_TIMER
    return 0;
}
