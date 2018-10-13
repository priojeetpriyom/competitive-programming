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



#define MX 200100
#define double long double
#define mod 100000007
#define mod2 1000000009

struct Edge;
typedef list<Edge>::iterator list_iter;

struct Edge{
  int v;
  list_iter reverse_iter;
  Edge( int v )
        :v(v){ }
};

list<Edge> conn[MX];

void add_edge(int u, int v) {

  conn[u].push_front(Edge(v));
  list_iter itu = conn[u].begin();

  conn[v].push_front(Edge(u));
  list_iter itv = conn[v].begin();

  conn[u].begin()->reverse_iter = itv;
  conn[v].begin()->reverse_iter = itu;

}

map<pair<int,int> , int> mapp;
int deg[MX];
vector<pii> ans(MX);
int HAS_CIRCUIT=2, HAS_PATH=1;

int is_eular_circuit_or_has_path(int n) {
  int cnt=0;
  for1(i, n) {
      if(deg[i]%2==1)
        cnt++;

  }

  if(!cnt)
    return HAS_CIRCUIT;
  else if(cnt==2)
    HAS_PATH;

  return 0;

}

vector<int> path;

void find_path(int u) {

  // cout<<"u "<<u<<" size "<<conn[u].size()<<endl;

    while(conn[u].size()) {
      int v = conn[u].begin()->v;
      conn[v].erase(conn[u].begin()->reverse_iter);
      conn[u].pop_front();

      // cout<<"u "<<u<<" v "<<v<<" u_size "<<conn[u].size()<<" v_size() "<<conn[v].size()<<endl;

      find_path(v);

    }
    path.push_back(u);



}


int main()
{

//    FAST_READ

  // FRE_IN_OUT

  // cout<<"aise\naise\n";

  int n,m;

  cin>>n>>m;

  for1(i, m) {
    int u, v;
    cin>>u>>v;

    add_edge(u,v);
    // add_edge(v, u);

    mapp[mp(u,v)] =i;

    // in[u]++, out[u]++;
    // in[v]++, out[v]++;
    deg[u]++, deg[v]++;

    //conn[u].add_edge

  }

  bool ok = true;

  for1(i, n)
    if(!deg[i])
      ok = false;

  int ret = is_eular_circuit_or_has_path(n);
  if(ret != HAS_CIRCUIT || !ok) {
    cout<<"NO"<<endl;
    return 0;
  }

  find_path(1);

  // assert(path.size()==m+1 && path[0]== path[m]);

  if(path.size()!=m+1 || path[0]!= path[m]) {
    cout<<"NO"<<endl;
    return 0;
  }

  reverse(path.rbegin(), path.rend());

  int prev = path[0];

  for(int i=1; i<path.size(); i++){
    int cur= path[i];
    if(mapp.find(mp(prev, cur)) != mapp.end()) {
      ans[mapp[mp(prev, cur)]] = mp(prev, cur);
      mapp.erase(mapp.find(mp(prev, cur)));
    } else {

        ans[mapp[mp(cur, prev)]] = mp(prev, cur);
        mapp.erase(mapp.find(mp(cur, prev)));
    }
    prev = cur;
  }

  cout<<"YES"<<endl;

  for1(i, m)
    cout<<ans[i].first<<" "<<ans[i].second<<endl;



    return 0;
}
