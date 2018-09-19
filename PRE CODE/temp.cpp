#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

//------------ loop macros

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define fr(i,start, till) for(int i=start; i<=till; i++)


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





#define MX 200100
#define double long double
#define mod 1000000007
#define mod2 1000000009

struct cell {
    int r, c;
};

char grid[MX] [MX];
int dist[MX] [MX];
//int vis[MX] [MX];
int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};
int n,m;

bool valid(cell prevcell, cell newcell) {
    if(newcell.r>0 && newcell.r <=n && newcell.c>0 && newcell.c<=m && grid[newcell.r][newcell.c]!= 'T' && dist[prevcell.r] [prevcell.c]+1 < dist[newcell.r] [newcell.c])
        return true;
    return false;
}

void bfs(cell start) {

    queue<cell> Q;

    Q.push(start);
    cell cur, newcell;

    while(!Q.empty()) {
        cur = Q.front();
        Q.pop();

        for0(i, 4) {
            newcell = {cur.r+ dr[i], cur.c + dc[i]};
            if(valid(cur, newcell)) {
                dist[newcell.r] [newcell.c] = dist[cur.r] [cur.c]+1;
                Q.push(newcell);
            }
        }

    }


}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    freopen("input.txt", "w", stdout);


//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    SET_TIMER


    sii(n, m);

    for1(i, n)
        for1(j, m)
            scs(grid[i]+1);

    cell start, goal;

    for1(i, n) {
        for1(j, m ) {
            if(grid[i][j]=='S') {
                start = {i, j};
            } else if(grid[i] [j]=='E') {
                goal = {i, j};
            }

            dist[i][j] = 1e9;
        }
    }

    bfs(start);

    int lim = dist[start.r] [start.c];
    int ans=0;
    for1(i, n) {
        for1(j, m) {
            if(grid[i][j]>='0' && grid[i][j]<='9' && dist[i][j]<=lim) {
                ans+= (grid[i][j]-'0');
            }
        }
    }
    pri(ans);
//    PRINT_TIMER
    return 0;
}
