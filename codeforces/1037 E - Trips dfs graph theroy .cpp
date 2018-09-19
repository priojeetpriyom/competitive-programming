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


int deg[MX];
set<pii> pset;
vector<pii> query;
set<int> conn[MX];


bool is_going(int u)
{

    return (pset.find(mp(deg[u], u)) != pset.end());
}

int n, m, k;

void delete_adjacent(int u)
{
//    cout<<"cur u "<<u<<" cur.size "<<conn[u].size()<<endl;
    for(auto v : conn[u])
    {
//    cout<<"v "<<v<<endl;
        conn[v].erase(conn[v].find(u));
        if(is_going(v))
        {
            pset.erase(pset.find(mp(deg[v], v)));

//            conn[u].erase(conn[v].find(u));

            deg[v]--;
            if(deg[v]< k)
            {
                delete_adjacent(v);
            }
            else
                pset.insert(mp(deg[v], v));
        }

    }
//    for(auto v : conn[u]) {
//        if(deg[v]< k) {
//            conn[v].erase(conn[v].find(u));
//            }
//    }
    conn[u].clear();


}

void print_set()
{
    if(!pset.size())
        cout<<"Set is empty"<<endl;

    for(auto p : pset)
        cout<<p.second<<","<<p.first<<" ";
    cout<<endl;
}

vector<int>ans(MX);

int main()
{
//    FAST_READ


    cin>>n>>m>>k;

    for1(i, m)
    {
        int u, v;
        cin>>u>>v;
        deg[u]++;
        deg[v]++;
        query.pb({u, v});
        conn[u].insert(v);
        conn[v].insert(u);
    }

    for1(i, n)
    {
        pset.insert(mp(deg[i], i));
//        cout<<deg[i]<<" ";
    }

//    for(set<pii>:: iterator it: pset) {
//        if(it->first < k)
//        {
//            pset.erase(it);
//        }
//    }

    for1(i, n)
    {
        if(deg[i]<k && is_going(i))
        {
            pset.erase(mp(deg[i], i));
            delete_adjacent(i);
//            cout<<"i "<<i<<" delete_node printset"<<endl;
//            print_set();
        }
    }


    frr(i, m-1, 0)
    {

//        cout<<"pre i "<<i<<" printset"<<endl;
//        print_set();


        int u = query[i].first;
        int v = query[i].second;

        ans[i+1] = pset.size();

        if(pset.find(mp(deg[u], u)) != pset.end() && pset.find(mp(deg[v], v)) != pset.end() )
        {

//            conn[u].erase(conn[u].find(v));
//            conn[v].erase(conn[v].find(u));

//            cout<<"u "<<u<<" v "<<v<<" degU "<<deg[u]<<" degV "<<deg[v]<<endl;

            if(deg[u]-1>=k && deg[v]-1>=k )
            {
                pset.erase(pset.find(mp(deg[u], u)));
                pset.erase(pset.find(mp(deg[v], v)));

                conn[u].erase(conn[u].find(v));
                conn[v].erase(conn[v].find(u));

                deg[u]--;
                deg[v]--;
                pset.insert(mp(deg[u], u));
                pset.insert(mp(deg[v], v));
            }
            else if(deg[u]<=k)
            {
                pset.erase(pset.find(mp(deg[u], u)));
                deg[u]--;
                delete_adjacent(u);
            }
            else
            {
            pset.erase(pset.find(mp(deg[v], v)));
                deg[v]--;
                delete_adjacent(v);
            }
        }



//        cout<<"post i "<<i<<" printset"<<endl;
//        print_set();


//        break;
    }

    for1(i, m)
    cout<<ans[i]<<endl;
    cout<<endl;

    return 0;
}

