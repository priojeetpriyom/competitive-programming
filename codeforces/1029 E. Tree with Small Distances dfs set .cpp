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


#define scs(s) scanf("\n%s", s)
#define scss(s, ss) scanf("\n%s \n%s", s, ss)


//--------------output----------

#define pr printf
#define pri(n) printf("%d\n", n);
#define prl(n) printf("%lld\n", n);
#define prll(n, m) printf("%lld %lld\n", n, m);
#define prd(n) printf("%.10lf\n", n);
#define prs(str) printf("%s\n", str);

// ------------- BIT MANIPULATION ------------

#define CHECK(n, pos) ( (n& (1<<pos))>0)
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
#define pb push_back
#define mp make_pair



#define MX 200100
#define double long double
#define mod 1000000007
#define mod2 1000000009


vector<int> conn[MX];
set<pii> sset;
int dists[MX];
int pars[MX];

void rec(int u, int dist, int par) {
//    cout<<"u "<<u<<" dist "<<dist<<" par "<<par<<endl;

    if(dist>2)
        sset.insert(make_pair(dist, u));

    dists[u] = dist;
    pars[u]=par;

    if(conn[u].size()==1){
//        cout<<"LEAF node reached dist "<<dist<<endl;
        return;
    }
    for(int v: conn[u]) {
        if(v==par)
            continue;
//            mn = min(mn, rec(v, 2, u)+1);
//                mn = min(mn, rec(v, dist+1, u));
        rec(v, dist+1, u);
    }

}

void check_erase(pii p) {
    if(sset.find(p)!= sset.end())
        sset.erase(sset.find(p));

}

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

    for1(i, n-1)
    {
        int u, v;
        sii(u, v);
        conn[u].pb(v);
        conn[v].pb(u);
    }

    int ans=0;
    for(int v: conn[1]) {
        rec(v, 1, 1);
    }


    while(!sset.empty()) {
        pii cur = *(--sset.end());
        int par = pars[cur.second];
//        cout<<"cur "<<cur.second<<" par "<<par<<endl;
        check_erase(mp(dists[par], par));
        for(int v: conn[par])
            check_erase(mp(dists[v], v));
        ans++;
    }

    pri(ans)

//    cout<<ans<<endl;

//    PRINT_TIMER
}
