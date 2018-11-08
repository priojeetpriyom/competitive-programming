/*
    algo:
    idea:

*/


#include <iostream>
#include <string.h>
#include <assert.h>

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
#define FRE_IN_OUT FRE_IN FRE_OUT
#define FRE_IN freopen("in.txt", "r", stdin);
#define FRE_OUT freopen("out.txt", "w", stdout);
// inline void inp_int( int &n ){n=0;int ch=getchar_unlocked();int sign=1;while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}while(  ch >= '0' && ch <= '9' )n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();n=n*sign;}



#define MX 2002
#define double long double
#define mod 100000007
#define mod2 1000000009

//Esqrt(V) Complexity
//0 Based
//Edge from set a to set b
const int MAXN1 = 2002; //nodes in set a
const int MAXN2 = 2002; //nodes in set b
const int MAXM = 4010; //number of edges

int n1, n2, edges, last[MAXN1], prevv[MAXM], head[MAXM];
int matching[MAXN2], dist[MAXN1], Q[MAXN1];
bool used[MAXN1], vis[MAXN1]; //vis is cleared in each dfs

// n1 = number of nodes in set a, n2 = number of nodes in set b
void init(int _n1, int _n2) {
    n1 = _n1;
    n2 = _n2;
    edges = 0;
    fill(last, last + n1, -1);
}

void addEdge(int u, int v) {
    head[edges] = v;
    prevv[edges] = last[u];
    last[u] = edges++;
}

void bfs() {
    fill(dist, dist + n1, -1);
    int sizeQ = 0;
    for (int u = 0; u < n1; ++u) {
        if (!used[u]) {
            Q[sizeQ++] = u;
            dist[u] = 0;
        }
    }
    for (int i = 0; i < sizeQ; i++) {
        int u1 = Q[i];
        for (int e = last[u1]; e >= 0; e = prevv[e]) {
            int u2 = matching[head[e]];
            if (u2 >= 0 && dist[u2] < 0) {
                dist[u2] = dist[u1] + 1;
                Q[sizeQ++] = u2;
            }
        }
    }
}

bool dfs(int u1) {
    vis[u1] = true;
    for (int e = last[u1]; e >= 0; e = prevv[e]) {
        int v = head[e];
        int u2 = matching[v];
        if (u2 < 0 || (!vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2))) {
            matching[v] = u1;
            used[u1] = true;
            return true;
        }
    }
    return false;
}

int augmentPath() {
    bfs();
    fill(vis, vis + n1, false);
    int f = 0;
    for (int u = 0; u < n1; ++u)
        if (!used[u] && dfs(u))
            ++f;
    return f;
}

int maxMatching() {
    fill(used, used + n1, false);
    fill(matching, matching + n2, -1);
    for (int res = 0;;) {
        int f = augmentPath();
        if (!f)
            return res;
        res += f;
    }
}


// vector<int> conn[MX];
// vector<pii> inp_edges;
int idx[MX][MX]; //, col[MX];
int dr[] = {-1, 0, 1,0};
int dc[] = {0, 1, 0, -1};

int main() {
    // FRE_IN_OUT

    // char c;
    // while(c = getchar_unlocked())
    // cout<<c<<endl;
    // return 0;

    int n, m, k;
    int t;
    // si(t)
    // inp_int(t);
    // for1(tc, t) {

        while(cin>>n>>m>>k) {
        mem(idx, -1);

        for1(i, n) {
            for1(j, m)
                idx[i][j]=0;
        }

        for0(i, k) {
            int r,c;
            sii(c, r)
            idx[r][c] = -1;
        }

        int tot=0, one=0, two=0;

        for1(i, n) {
            int cur = (i&1);
            for1(j, m) {
                if(~idx[i][j]) {

                    if(!cur) {
                        idx[i][j] = tot; one++;
                    } else
                    {
                        idx[i][j] = tot; two++;
                    }
                        tot++;
                    // cout<<"r "<<i<<" c "<<j<<" col "<<cur<<" idx "<<idx[i][j]<<endl;
                }
                cur^=1;
            }
        }
        init(tot, tot);

        // for1(i, n) {
        //     for1(j, m)
        //         cout<<idx[i][j]<<" "; cout<<endl;
        // }

        for1(r, n) {
            int cur = (r&1);
            for1(c, m) {
                if(idx[r][c]==-1) continue;
                // cout<<"R "<<i<<" C "<<j<<endl;
                for(int l=0; l<4; l++) {
                    int i = r+ dr[l];
                    int j = c+ dc[l];
                    if(i<1 || i>n || j<1 || j>m)
                        continue;

                    if(~idx[i][j]) {

                        // if(!cur) {
                            addEdge(idx[r][c], idx[i][j]);
                        // }else{
                        //     addEdge(idx[i][j], idx[r][c]);
                        // }
                    }
                }
                cur^=1;
            }
        }



        // PRINT_LOJ_TC
        int match = maxMatching();
        // cout<<"match "<<match<<endl;
        if(match*2 == tot) {
            assert((tot%2==0) && (one == two));
        }
        // printf("%d\n", (n - match));
        cout<<(tot== match ? "YES":"NO")<<endl;

    }

    return 0;
}
