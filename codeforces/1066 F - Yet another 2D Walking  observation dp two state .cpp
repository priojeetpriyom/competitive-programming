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

#define MX 100050
#define double long double
#define mod 100000007
#define mod2 1000000009

#define inp_int(n) inline void inp( int &n ){n=0;int ch=getchar_unlocked();int sign=1;while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}while(  ch >= '0' && ch <= '9' )n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();n=n*sign;}


ll dist(pll one, pll two) {
   return abs(one.first - two.first) + abs(one.second - two.second);
}

bool cmp (pll a, pll b) {
  if(a.first != b.first)
      return a.first< b.first;
    return a.second > b.second;
}

ll dp[4*MX] [5];
map<int, vector<pll> > mapp;

int main()
{
  // SET_TIMER
   FAST_READ
   // FRE_IN
   //FRE_OUT
  // FRE_IN_OUT

  int n;

  cin>>n;

  for1(i, n) {
      int x, y;
      cin>>x>>y;

      mapp[max(x, y) ].pb(mp(x, y));

  }
  int pos=1;
  mapp[0].pb(mp(0, 0));
  // mapp[0].clear();
  pll prevl, prevr, curl, curr;
  prevl = prevr = {0,0};
  dp[0][0] = dp[0][1]= dist(mapp[0][0], mapp[0].back());

  for(pair<int, vector<pll> > m: mapp) {
     sort(m.second.begin(), m.second.end(), [] (pll a, pll b) {
       if(a.first != b.first)
           return a.first< b.first;
         return a.second > b.second;
     });

     curl = m.second[0];
     curr = m.second.back();

     dp[pos][0]= dp[pos][1] = 1e17;

     dp[pos] [0] =                 dp[pos -1 ] [0] + dist(prevl, curr) + dist(curr, curl);
     dp[pos] [0] = min(dp[pos][0], dp[pos -1 ] [1] + dist(prevr, curr) + dist(curr, curl));
     dp[pos] [1] = min(dp[pos][1], dp[pos -1 ] [0] + dist(prevl, curl) + dist(curr, curl));
     dp[pos] [1] = min(dp[pos][1], dp[pos -1 ] [1] + dist(prevr, curl) + dist(curr, curl));

     prevl = curl, prevr = curr;
     pos++;
 }

 cout<<min(dp[pos-1][0], dp[pos-1] [1])<<endl;


  // PRINT_TIMER

    return 0;
}