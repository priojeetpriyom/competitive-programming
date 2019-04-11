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
#define log2ceil(n) ( (ll) ceil(log2(n)))
#define pow2(n) (1<<n)


#define MX 200100
#define double long double
#define mod 1000000007
#define mod2 1000000009

set<int> conn[MX];
//int dist[MX];

queue<int> Q;
//multiset<int> mset;
//void calc_dist() {
//
//    Q.push(1);
//    int cur;
//    int len;
//    while(!Q.empty()) {
//        cur = Q.front();
//        Q.pop();
//        mset.insert(dist[cur]);
//
//        len = conn[cur].size();
//        for(int i=0; i<len; i++) {
//            if(dist[conn[cur][i] ]> dist[cur]+1) {
//                dist[conn[cur][i]] = dist[cur]+1;
//                Q.push(conn[cur] [i]);
//            }
//        }
//    }
//
//}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    freopen("input.txt", "w", stdout);
//    cout<<1000<<" "<<1000<<" "<<1000000<<" "<<100<<endl;
//
//    for1(i, 1000)
//    {
//        for1(j, 1000) {
//            cout<<"1 ";
//        }
//        cout<<endl;
//    }
//    exit(0);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    SET_TIMER

    int n;

    cin>>n;

    for1(i, n-1) {
        int u, v;
        cin>>u>>v;
        conn[u].insert(v);
        conn[v].insert(u);
//        dist[i+1] = 1e9;
    }



//    dist[n]= 1e9;

//    calc_dist();

    int x;
    Q.push(0);
    conn[0].insert(1);
    conn[1].insert(0);
    for1(i, n) {
        cin>>x;
        int cur = Q.front();
        while(conn[cur].size()==0) {
            Q.pop();
            cur = Q.front();
        }

//        cout<<"cur "<<cur<<" x "<<x<<endl;

        if(conn[cur].find(x) == conn[cur].end()) {
            cout<<"No"<<endl;
            return 0;
        }
        conn[cur].erase(conn[cur].find(x));
        conn[x].erase(conn[x].find(cur));
        Q.push(x);
//        if(conn[cur].size()==0)
//            Q.pop();
    }

    cout<<"Yes"<<endl;

//    PRINT_TIMER
}
