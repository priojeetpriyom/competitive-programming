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

#define scs(s) scanf("\n%s", s)
#define scss(s, ss) scanf("\n%s \n%s", s, ss)


//--------------output----------

#define pr printf
#define pri(n) printf("%d\n", n);
#define prl(n) printf("%lld\n", n);

// ------------- BIT MANIPULATION ------------

#define CHECK(n, pos) ( (n& (1<<pos))>0)
#define SET(n,pos) (n | (1<<pos))
#define RESET(n,pos) (n ^ (1<<pos))
#define mem(ara, val) memset(ara, val, sizeof ara);


//--------others
#define SET_TIMER double timer =(double) clock();
#define PRINT_TIMER cout<<(clock()- timer)/CLOCKS_PER_SEC<<endl;





#define MX 1011
#define double long double
#define mod 1000000007
#define mod2 1000000009

int n, m;
int grid[MX] [MX];


ll dp11toij[MX] [MX];
ll dpijtonm[MX] [MX];
ll dpn1toij[MX] [MX];
ll dpijto1m[MX] [MX];


int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    freopen("input.txt", "w", stdout);


//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    SET_TIMER

    sii(n, m);

    for1(i, n)
        for1(j, m)
             si(grid[i][j]);


    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            dp11toij [i][j] = max(dp11toij[i-1] [j], dp11toij[i] [j-1])+ grid[i][j];
        }
    }

    for(int i=n; i>=1; i--) {
        for(int j=m; j>=1; j--) {
            dpijtonm [i][j] = max(dpijtonm[i+1] [j], dpijtonm[i] [j+1])+ grid[i][j];
        }
    }

    for(int i=n; i>=1; i--) {
        for(int j=1; j<=m; j++) {
            dpn1toij [i][j] = max(dpn1toij[i+1] [j], dpn1toij[i] [j-1])+ grid[i][j];
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=m; j>=1; j--) {
            dpijto1m [i][j] = max(dpijto1m[i-1] [j], dpijto1m[i] [j+1])+ grid[i][j];
        }
    }


    ll ans=0;

    for(int i=2; i<n; i++) {
        for(int j=2; j<m; j++) {
            ans = max(ans, dp11toij[i][j-1] + dpijtonm[i][j+1] + dpn1toij[i+1] [j] + dpijto1m[i-1] [j]);
            ans = max(ans, dp11toij[i-1][j] + dpijtonm[i+1][j] + dpn1toij[i] [j-1] + dpijto1m[i] [j+1]);
        }
    }

    prl(ans);

//    PRINT_TIMER
    return 0;
}
