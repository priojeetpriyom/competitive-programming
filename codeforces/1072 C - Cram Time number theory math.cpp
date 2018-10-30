/*
    algo:
    idea:

*/


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


ll n;

ll calc(ll val) {


  if(val&1)
    return val * ((val+1)>>1);

  return (val>>1) * (val+1);
}

ll b_search(ll low, ll high) {
  ll mid;
  while(low<=high) {
      mid = (low+high)>>1;
      ll ret = calc(mid);
      if(ret<= n)
        low =mid+1;
      else
        high= mid-1;
      }
      low = max(0LL, low-1);

    return low;

}

  vector<ll> patha, pathb;
  unordered_map<ll, int> vis;
int main()
{
//    FAST_READ

  ll a, b;
  cin>>a>>b;

  n = a+b;

  ll mx = b_search(0, max(a, b));

  // cout<<"mx "<<mx<<" a "<<a<<" b "<<b<<endl;

  // mem(vis, 0)

  while(a && mx) {
    if(a>=mx) {
      patha.push_back(mx);
      vis[mx]=1;
      a-=mx;
      mx--;
    } else {
      vis[a]=1;
      patha.push_back(a);
      break;
    }
  }
  // cout<<"mx after a "<<mx<<endl;

  // for1(i, 5)
  // cout<<vis[i]<<" ";
  // cout<<endl;

  while(b && mx) {
    // cout<<"b "<<b<<" mx "<<mx<<" pathb_size "<<pathb.size()<<endl;
    if(b>=mx) {
      if(vis.find(mx) == vis.end()) {
        pathb.push_back(mx);
        b-=mx;
        vis[mx]=1;
      }
      mx--;
    } else {
      int pos=b;
      while(vis[pos] && pos)
        pos--;
      if(pos)
        pathb.push_back(b);
      break;
    }
  }

  cout<<(int)patha.size()<<endl;

  for(int i=0; i<patha.size(); i++)
    cout<<patha[i]<<" ";
  cout<<endl;


  cout<<((int)pathb.size())<<endl;

  for(ll p: pathb)
    cout<<p<<" ";
  cout<<endl;
    return 0;
}
