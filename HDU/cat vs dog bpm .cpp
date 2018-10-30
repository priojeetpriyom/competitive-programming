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
#define FRE_IN_OUT FRE_IN FRE_OUT
#define FRE_IN freopen("in.txt", "r", stdin);
#define FRE_OUT freopen("out.txt", "w", stdout);



#define MX 205
#define double long double
#define mod 100000007
#define mod2 1000000009

//Esqrt(V) Complexity
//0 Based
//Edge from set a to set b
const int MAXN1 = 50010; //nodes in set a
const int MAXN2 = 50010; //nodes in set b
const int MAXM = 150010; //number of edges

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

// int a[105], b[105];
// char str[10], a[10], b[10];

// vector<int> c_like[MX], d_like[MX],c_dislike[MX], d_dislike[MX];
vector<int> inpd, inpc;

// #define CAT 111
// #define DOG 112

// int taken[505] [505];

int main() {
    // FRE_IN_OUT

    int n, m, p;

    while(scanf("%d %d %d", &n, &m, &p)==3) {
        init(p, p);

        // for0(i, max(n,m)+1)
        // {
        //     c_like[i].clear();
        //     d_like[i].clear();
        //     c_dislike[i].clear();
        //     d_dislike[i].clear();
        // }
        inpd.clear();
        inpc.clear();
        // mem(taken, 0);

        for0(i, p) {
            // scss(a, b);
            char ca, cb;
            int one, two;
            scanf("\n%c %d \n%c %d",&ca, &one, &cb, &two );
            // int one = atoi(a+1);
            // int two = atoi(b+1);
            // cout<<one<<" "<<two<<endl;
            if(ca=='C') {
                // c_like[one].pb(i);
                inpc.pb(one);
                inpc.pb(two);
                inpc.pb(i);
            } else
            {
            inpd.pb(one);
            inpd.pb(two);
            inpd.pb(i);
            }


        }


        for(int i=0; i< inpc.size(); i+=3) {

            for(int j=0; j<inpd.size(); j+=3) {
                if( (inpc[i]==inpd[j+1]) || (inpc[i+1] == inpd[j]) ) {
                    // if(taken[i/4][j/4])   continue;
                    // taken[i/4] [j/4]=1;
                    // taken[j/4] [i/4]=1;
                    // vis[j]=0;

                    addEdge(inpc[i+2], inpd[j+2]);
                    // cout<<"p1 "<<inpc[i+2]<<" p2 "<<inpd[j+2]<<endl;
                }
            }
        }

        printf("%d\n", p - maxMatching());


    }

    return 0;
}
