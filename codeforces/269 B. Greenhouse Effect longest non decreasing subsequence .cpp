#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

//------------ loop macros

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)


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





#define MX 200011
#define double long double
#define mod 1000000007
#define mod2 1000000009


int ara[MX];
int cnt[MX];
int dp[MX];
pdi pairs[MX];

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    freopen("input.txt", "w", stdout);


//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    SET_TIMER
    int n, m;
    sii(n, m);

    int x;
    double d;

    for1(i, n) {
        sid(pairs[i].second,pairs[i].first);
    }
    sort(pairs+1, pairs+n+1);

//    cout<<"oka"<<endl;
    for1(i, n) {
        ara[i]= pairs[i].second;
        cnt[ara[i] ]++;
    }
//    for1(i, n) {
//        cout<<ara[i]<<" ";
//    }cout<<endl;

    int left = n;
    int ans=0;
//    int j=1;
    ara[n+1] = -1;
    int mx=1;
    for1(i, n) {
        dp[i]=1;
        for1(j, i-1) {
            if(ara[i]>=ara[j])
                dp[i] = max(dp[i], dp[j]+1);
        }
        mx= max(mx, dp[i]);
//        cout<<"i "<<i<<" ara[i] "<<ara[i]<<" dp[i] "<<dp[i]<<endl;
    }




    pri(n- mx);


//    PRINT_TIMER
    return 0;
}
