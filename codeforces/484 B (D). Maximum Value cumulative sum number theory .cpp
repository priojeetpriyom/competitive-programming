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
#define prll(n, m) printf("%lld %lld\n", n, m);

// ------------- BIT MANIPULATION ------------

#define CHECK(n, pos) ( (n& (1<<pos))>0)
#define SET(n,pos) (n | (1<<pos))
#define RESET(n,pos) (n ^ (1<<pos))
#define mem(ara, val) memset(ara, val, sizeof ara);


//--------others
#define SET_TIMER double timer =(double) clock();
#define PRINT_TIMER cout<<(clock()- timer)/CLOCKS_PER_SEC<<endl;





#define MX 200011
#define double long double
#define mod 1000000007
#define mod2 1000000009

//int ara[MX];
int lesser[MX*20];
int vis[MX*20];

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    freopen("input.txt", "w", stdout);


//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    SET_TIMER
    int n;
    si(n);
    int mx=0, x;
    for1(i, n) {
        si(x);
        vis[x]=1;
        mx = max(mx, x<<1);
    }
    int prev=0;
    for1(i, mx) {
        lesser[i] = prev;
        if(vis[i])
            prev = i;
    }

    int ans=0;

    for1(i, mx>>1) {
        if(vis[i]) {
            for(int j = i<<1; j<=mx; j+= i) {
                ans = max(ans, lesser[j]%i);
//            cout<<"j "<<j<<" lesser[j] "<<lesser[j]<<" ara[i] "<<i<<endl;
            }
        }
    }


    pri(ans);


//    PRINT_TIMER
    return 0;
}
