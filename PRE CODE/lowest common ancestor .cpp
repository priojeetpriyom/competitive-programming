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



#define MX 100100
#define double long double
#define mod 1000000007
#define mod2 1000000009

vector<int> conn[MX];
int n, m;
int level[MX];
int par [MX] [33];
bool vis[MX];
int dfs(int curNode, int lvl) {
    level[curNode] = lvl;
    int len = conn[curNode].size();
    vis[curNode] = true;

    for(int i=0; i<len; i++) {
        if(!vis[conn[curNode] [i]]) {
            int x = dfs(conn[curNode] [i], lvl+1);
            par[x] [0] = curNode;

        }
    }
    return curNode;
}


void build_sparse_table() {
//    printf("oka\n");
    memset(vis, 0, sizeof(vis));
    dfs(1, 1);
    for(int i = 1; i<11; i++)
        printf("%d ",level[i]);
    printf("\n");
    par[1] [0] = -1;
    for(int j=1; j<11; j++) {
        for(int i=1; i<=n; i++) {
            if(par[i] [j-1] != -1)
                par[i] [j] = par[par[i] [j-1]] [j-1];
        }
    }
}


int matchLevel(int u, int v) {

    for(int i= 30; i>=0; i--) {
        if(par[u][i]!= -1 && level[par[u][i] ] >= level[v])
            u = par[u] [i];
    }
    return u;
}

int findLca(int u, int v) {
    if(level[u] > level[v])
        u = matchLevel(u,v);
    else if(level[v] > level[u])
        v= matchLevel(v, u);

    if(u==v)
        return u;

    for(int i=30; i>=0; i--) {
        if(par[u][i] != -1 && par[v] [i]!=-1 && par[u][i] != par[v][i] )
        {
            u = par[u][i];
            v= par[v] [i];
        }
    }
    return par[u] [0];
}

void init(int n = MX-1) {
    memset(par, -1, sizeof(par));
    memset(vis, 0, sizeof(vis));
    for(int i=0; i<=n; i++) {
        conn[i].clear();
    }

}

int main()
{
//    freopen("myOut.txt", "w", stdout);
    cin>>n>>m;
    init();
    int u,v, d;
    for(int i=0; i<m; i++)  {
        scanf("%d %d", &u, &v);
        conn[u].push_back(v);
        conn[v].push_back(u);
    }
    build_sparse_table();

//    printf("oka\n");
    while(scanf("%d %d", &u, &v)==2) {
        cout<<findLca(u,v)<<endl;
    }
    return 0;
}

/*
10 9
1 2
1 3
2 4
2 5
3 6
3 7
4 8
4 9
5 10
 */
