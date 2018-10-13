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

int n, ar, ac, br, bc, cr,cc;
int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dc[] = {-1, 0,   1, 1, 1, 0, -1, -1};
int vis[1011] [ 1011];
int mark[1011] [ 1011];

void bfs() {


  queue<int> q;
  q.push(br);
  q.push(bc);

  while(!q.empty()) {

        int r, c;
        r = q.front(); q.pop();
        c = q.front(); q.pop();

        if(r<1 || r>n || c<1 ||c>n || vis[r][c] || mark[r][c])
          continue;

        vis[r][c]=1;

        if(r == cr && c == cc)
        {
          cout<<"YES"<<endl;
          exit(0);
        }

        for(int i=0; i<8; i++)
        {
          q.push(r+dr[i]);
          q.push(c+dc[i]);
        }

  }

}


int main()
{
//    FAST_READ


  cin>>n>>ar>>ac>>br>>bc>>cr>>cc;


  for(int i=1; i<=n; i++)
  {
    mark[i][ac] = 1;
    mark[ar][i] = 1;
  }
  int tr = max(0, ar-ac);
  int tc = ac - min(ar, ac);

  for(int i=1; i+tr<=n && i+tc<=n; i++) {
    mark[i+tr] [i+tc]=1;
  }

  tr = ar + min(n-ar, ac-1) +1;
  tc = ac - min(n-ar+1, ac);

  for(int i=1; tr-i>0 && i+tc<=n; i++) {
    mark[tr-i] [i+tc]=1;
  }

  // for1(i, n)
  //   {
  //     for1(j, n) {
  //       cout<<mark[i][j]<<" ";
  //     } cout<<endl;
  //   }

  bfs();

  cout<<"NO"<<endl;
  return 0;




    return 0;
}
