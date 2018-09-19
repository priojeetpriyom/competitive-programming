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





#define MX 5005
#define double long double
#define mod 1000000007
#define mod2 1000000009


char str[MX] [MX];
//int cnt[MX];
int cum[MX][MX];

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
    int n, m;

    sii(n, m);

    for1(i, n) {
        scs(str[i]+1);
//        for1(j, m) {
//            if(str[i][j]=='1') {
//                cnt[j]++;
//            }
//        }
    }

    for1(i, n) {
        for(int j = m; j>=1; j--) {
            cum[i][j] = (str[i][j] == '1') ? cum[i][j+1]+1: 0;
        }
    }

//    for1(r, n) {
//        for1(c, m) {
//            cout<<cum[r][c]<<" ";
//        }cout<<endl;
//    }

    int ans=0;

    int rows[MX];

    for1(c, m) {
        for1(r, n)
            rows[r] = cum[r][c];
        sort(rows+1, rows+n+1);

        for1(r, n)
            ans = max(ans, rows[r] * (n-r+1));
    }

    pri(ans);


//    PRINT_TIMER
    return 0;
}
