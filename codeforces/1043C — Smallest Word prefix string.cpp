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



#define MX 1010
#define double long double
#define mod 1000000007
#define mod2 1000000009


struct node{
  string s;
  vector<int> positions;
};


string str_rev(string s) {
  string temp = string(s);
  reverse(temp.begin(), temp.end());
  return temp;
}

int vis[MX];

int main()
{
  // cout<<str_rev("123")<<endl;
//    FAST_READ

  int n;
  // cin>>n;
  string s;
  cin>>s;

  node ans, mx, mn;
  mn.s = s[0];
  mx.s = s[0];

  ans.s = s;


  n = s.size();

  for1(i, n-1) {
      // if(s.substr(i-1, 1) +str_rev(mn.s) > mx.s) {
      //   mx.s = s.substr(0, i-1);
      //   mx.positions.clear();
      // }
      //   if(ans.s > mx.s) {
      //     ans.s = s.substr(0, i-1);
      //     mx.positions.clear();
      //   }
      string temp = s.substr(i, 1)+str_rev(mx.s);
      if(temp < ans.s) {
        ans.s = temp;
        ans.positions = std::vector<int>(mx.positions);
        ans.positions.pb(i);
      } else
        ans.s+= s[i];

      mx.s+=s[i];
      mn.s+=s[i];
      bool change_mx=false, change_mn=false;

      // if()
      if(str_rev(mn.s)>mx.s) {
        // mx.s = str_rev(mx.s);
        // mx.positions
        change_mx = true;
      }
      if(str_rev(mx.s)<mn.s) {
        // mx.s = str_rev(mx.s);
        // mx.positions
        change_mn = true;
      }

      if(change_mx && change_mn) {
        swap(mx, mn);
        mx.positions.pb(i);
        mn.positions.pb(i);
      } else if(change_mx ) {
        mx.s = str_rev(mn.s);
        mx.positions = std::vector<int> (mn.positions);
        mx.positions.pb(i);
      } else if(change_mn){
        mn.s = str_rev(mx.s);
        mn.positions = std::vector<int> (mx.positions);
        mn.positions.pb(i);

      }
      // cout<<"i "<<i<<" mx "<<mx.s<<" mn "<<mn.s<<endl;

  }

  // cout<<ans.s<<endl;
        for(auto i : ans.positions) {
          vis[i]=1;
        //   cout<<i<<" ";
        }
        // cout<<endl;

        for0(i, n)
          cout<<vis[i]<<" ";
        cout<<endl;

    return 0;
}
