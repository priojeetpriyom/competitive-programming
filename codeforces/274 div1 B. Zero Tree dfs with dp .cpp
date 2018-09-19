/*
    algo:
    idea:

*/
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;


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
#define FAST_READ ios_base::sync_with_stdio(0); cin.tie(0);



#define MX 200100
#define double long double
#define mod 1000000007
#define mod2 1000000009


ll ara[MX];
vector<int> conn[MX];

ll incs[MX], decs[MX];


ll dfs(int u, int par) {

//    if(conn[u].size()==1 && par)
//    {
//        if(ara[u]<0)
//            incs[u] = ara[u];
//        else
//            decs[u] = ara[u];
//
//        return ara[u];
//    }

    ll ret=0;
    ll I=0, D=0;

    for(auto v: conn[u]) {
//    cout<<"u "<<u<<" v "<<v<<endl;
        if(v!=par) {
            ll cost = dfs(v, u);
//            if(cost> ara[u]) {
//                mx = max(mx, cost- ara[u]);
//            }
//            else
//                cost = ara[u];
//            ret = max(ret,  cost);
            I = max(I, incs[v]);
            D = max(D, decs[v]);
        }
    }

    ret = ara[u] + (I - D);

    if(ret>0) {
        D+= (ret);
    } else
        I+= (-ret);

    incs[u] = I;
    decs[u] = D;

//    cout<<"u "<<u<<" I "<<I<<" D "<<D<<" ret "<<ret<<endl;

//    cout<<"u "<<u<<" ara "<<ara[u]<<" ret "<<ret<<endl;
//    if(ret<0) {
//        ara[u]+=   abs(ret);
//        return ret;
//    }

    return ret;

}

int main()
{
//    FAST_READ

    int n;

    cin>>n;

    for1(i, n-1) {
        int u, v;
        cin>>u>>v;
        conn[u].pb(v);
        conn[v].pb(u);
//        cout<<"inp u "<<u<<" v "<<v<<endl;
    }

    for1(i, n)
        cin>>ara[i];


//    if(n==1) {
//
//        cout<<ara[1]<<endl;
//        return 0;
//    }


//    cout<<conn[1].size()<<endl;

//    ll pre= abs(calc_incs(1, 0) );

//    for1(i, n)
//        cout<<ara[i]<<" ";
//    cout<<endl;
    dfs(1, 0);

//    for1(i, n) {
//
//    }

    cout<<incs[1]+ decs[1]<<endl;
    return 0;
}

