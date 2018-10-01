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
#define prii(n, m) printf("%d %d\n", n, m);
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



#define MX 1010
#define double long double
#define mod 1000003
#define mod2 1000000009


int res[MX] [MX];
int par[MX], vis[MX];

int get_new_flow(int s, int mn, const int & e, const int & n)
{
    int u = s;
    if(u == e)
        return 0;

    queue<int> q;

    q.push(u);
    vis[u]=1;
    while(!q.empty())
    {

        u = q.front();
        q.pop();
//        cout<<"u "<<u<<" q_size "<<q.size()<<endl;

        if(u == e)
        {
//            cout<<"destination mn "<<mn<<endl;
            break;
        }

        for1(i, n)
        {
            if(!vis[i] && res[u][i])
            {
//                cout<<"u "<<u<<" i "<<i<<endl;
                vis[i]=1;
//                mn = min(mn, res[u][i]);
                par[i] = u;
                q.push(i);
            }
        }
    }
    if(!vis[e])
        return 0;
//    cout<<"aise"<<endl;

    int cur=e;
    while(cur!=s)
    {
//        cout<<"cur "<<cur<<endl;
        int after = par[cur];

        mn = min(mn, res[cur] [par[cur]]);
        cur = par[cur];
    }
//    cout<<"mn "<<mn<<endl;

//    vis[u] = 0;
    return (mn==1e9? 0: mn);
}


int get_max_flow(int n, int s, int e)
{

    int flow = 0;

    while(1)
    {
        mem(par, 0)
        mem(vis, 0)
        int new_flow = get_new_flow(s,1e9,  e, n);

//         pr("new_flow %d\n", new_flow);

        if(new_flow)
        {
            int cur=e;
            while(cur!=s)
            {
                int after = par[cur];

                res[cur] [after] -= new_flow;
                res[after] [cur] -= new_flow;
                assert(res[cur] [after]>=0);
                assert(res[after] [cur]>=0);

                cur = after;
            }
            flow+=new_flow;
        }
        else
            break;
    }

    // pr("returned");
    return flow;

}


int main()
{

    // cout<<nCr(3, 0)+nCr(3,1) +1;
    // cout<<big_mod(2,10)<<endl;
//    FAST_READ

    // freopen("in.txt", "r", stdin);
//   freopen("out.txt", "w", stdout);

    int t;

    si(t)

    int s, e,n,  m;

    for1(tc, t)
    {
        si(n);
        siii(s, e, m)

        mem(res, 0)

        for1(i, m)
        {
            int u, v, cost;
            siii(u, v, cost);

            res[u][v]+=cost;
            res[v][u]+=cost;

            // pr("\n%d %d => %d\n", u, v, cost);
            //
            // conn[u].pb(v);
            // conn[v].pb(u);

            // conn[u].pb({v, cost});
            // conn[v].pb({u, cost});
            // conn[u][conn[u].size()-1].set_reverse_iterator(conn[v].begin()+ (conn[v].size()-1));
            // conn[v][conn[v].size()-1].set_reverse_iterator(conn[u].begin()+ (conn[u].size()-1));
        }
        // pr("input done\n");

        int ret = get_max_flow(n, s, e);

        PRINT_LOJ_TC
        pri(ret)

        // pr("finished");

    }
    return 0;
}
