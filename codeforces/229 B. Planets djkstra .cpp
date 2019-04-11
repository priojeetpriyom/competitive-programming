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

int n, m;
vector<pll> conn[MX];
map<ll, ll> skip[MX];
ll cost[MX];

struct node{
    ll u, cost;
};

bool comp(node a, node b) {
    return a.cost<b.cost;
}

priority_queue<node, vector<node>, decltype(&comp)> pq(comp);

void djkstra() {

}

int main()
{
//    FAST_READ
// freopen("out.txt", "w", stdout);

    cin>>n>>m;

    for1(i,m) {
        int u,v,c;
        cin>>u>>v>>c;
        conn[u].pb(mp(v,c));
        conn[v].pb(mp(u,c));
    }

    for1(i,n) {
        int k, x;
        cin>>k;
        while(k--) {
            cin>>x;
            skip[i][x]=1;
        }
        cost[i] = 1e12;
    }

    for1(i,n) {
        if(!skip[i].size())
            continue;

        map<ll,ll>::iterator it=(--skip[i].end()), itn;

        if(it==skip[i].begin()) {
            it->second = it->first+1;
        } else {

            it->second = it->first+1;
            do{
                itn = it;
                --it;

                if(it->first+1 == itn->first) {
                    it->second == itn->second;
                } else {
                    it->second = it->first+1;
                }


            } while(it != skip[i].begin());
        }

    }


    djkstra();

    if(cost[n]==1e12) {
        cout<<-1<<endl;
    } else {
        cout<<cost[n]<<endl;
    }


    return 0;
}
