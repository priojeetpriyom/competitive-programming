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



#define MX 2033
#define double long double
#define mod 1000000007
#define mod2 1000000009


  int n;
  // ll dp[MX] [MX];
  char str[MX] [MX];
  // int vis[MX] [MX];
// vector<pii> starts;

// ll hash_val[MX] [MX];
// ll base= 257;

// ll rec(int r, int c) {
//   if(r==n && c==n) {
//     return hash_val[r][c];
//   }
//   if(r == n+1 || c == n+1)
//     return mod-1;
//
//     ll &ret = dp[r][c];
//
//     if(~ret)
//       return ret;
//   ret=0;
//   if(str[r+1][c]< str[r][c+1])
//     ret = rec(r+1, c);
//
//   else if(str[r][c+1]< str[r+1][c])
//     ret = rec(r, c+1);
//
//   else
//     ret = min(rec(r+1, c), rec(r, c+1));
//
//   ret+= hash_val[r][c];
//
//   if(ret>=mod)
//     ret%=mod;
//
//   return ret;
//
// }

string ans;

// void generate(int r, int c) {
//
//   cout<<"r "<<r<<" c "<<c<<" path "<<path<<endl;
//
//     if(r== n && c== n){
//       path+= str[r][c];
//       // cout<<"base_case ans "<<ans<<" path "<<path<<endl;
//       if((!ans.size()) || path<ans) {
//         ans = path;
//       }
//       return;
//     }
//     if(r>n || c>n)
//       return;
//
//     if(~vis[r][c])
//       return;
//     vis[r][c]=1;
//
//     // if(r==n+1 || c== n+1) {
//     //   path[0]=122;
//     //   return;
//     // }
//     path+= str[r][c];
//     // if(str[r+1][c]<str[r][c+1])
//     //   generate(r+1, c);
//     // else if(str[r+1][c]>str[r][c+1])
//     //   generate(r, c+1);
//     // else {
//       generate(r+1, c);
//       generate(r, c+1);
//     path.pop_back();
//
//     // }
//
// }
  vector<pii> P,Q;

  void bfs() {
    int r, c;
    while(!Q.empty()) {
    char mnc = 'z'+1;
      sort(Q.begin(), Q.end());
      Q.resize(unique(Q.begin(), Q.end()) - Q.begin());

      for0(i, Q.size()) {
        r = Q[i].first;
        c = Q[i].second;
        mnc = min(mnc, min(str[r+1][c],str[r][c+1]));
      }

      // cout<<"mnc char "<<mnc<<" int "<<(int)mnc<<endl;
      if(mnc<='z') {
        for0(i, Q.size()) {
          r = Q[i].first;
          c = Q[i].second;
          if(str[r+1][c] == mnc&& r+1<=n) {
            P.pb({r+1,c});
          }
          if(str[r][c+1] == mnc && c+1<=n) {
            P.pb({r,c+1});
          }
        }
        ans+= mnc;
        // cout<<"ans "<<ans<<endl;
      }
      swap(Q, P);
      P.clear();
      // cout<<"new q_size() "<<Q.size()<<endl;
      // for(auto q: Q)
      //   cout<<q.first<<" "<<q.second<<"; ";
      // cout<<endl;
    }

  }

int acnt[MX] [MX];
// ll pws[MX];

int main()
{
//    FAST_READ


  // cout<<(int)str[0][0];

  int k;

  cin>>n>>k;
  cin.ignore();

  // k = min(k, n+n-1);

    mem(str, 'z'+1);
      // for1(i, 1011){
      //
      //     for1(j, 1011) {
      //       str[i][j] = 122;
      //       // cout<<str[i][j]<<" ";
      //     }
      //     // cout<<endl;
      // }

  for1(i, n)
  {
    cin>>str[i]+1;
    str[i][n+1] = 'z'+1;
  }
  // cout<<str[1][1]<<endl;


  for1(i, n)
    for1(j, n) {
      acnt[i][j] = max(acnt[i-1][j], acnt[i][j-1]) + (str[i][j]=='a');
    }

  // for1(i, n){
  //
  //     for1(j, n) {
  //       cout<<acnt[i][j]<<" ";
  //     }
  //     cout<<endl;
  // }
  //
    // fr(i,0,  n+1){
    //
    //     fr(j,0,  n+1) {
    //       cout<<str[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


  // int pre_i=1, pre_j=1, pre_len;

  // rec(1, 1);

  // pws[0]=1;
  //
  // for1(i, 2005) {
  //   pws[i] = pws[i-1] * base;
  //   if(pws[i]>=mod)
  //     pws[i]%=mod;
  // }

    // for1(i, n){
    //     for1(j, n) {
    //       hash_val[i][j] = (str[i][j]-'a'+1) * pws[n+n - i- j +1];
    //     }
    // }

    // mem(dp, -1)

    // cout<<"aise"<<endl;
    // rec(1, 1);
    // cout<<"rec passed"<<endl;

    int mxlen=0;

    for1(i, n){
        for1(j, n) {
          if(acnt[i][j]+k >= i+j-1 ) {

              mxlen = max(mxlen, i+j-1);
          }
        }
    }

    // string temp = ;
    // for0(i, mxlen)
    //   temp+= "a";

      // cout<<"mxlen "<<mxlen<<endl;

    char mnc = 'z'+1;

    for1(i, n){
        for1(j, n) {
          // if((acnt[i][j]+k == mxlen))
          //   cout<<"i "<<i<<" j "<<j<<" mxlen "<<mxlen<<endl;
          if( (acnt[i][j]+k >= mxlen) && (i+j-1 == mxlen)) {
            // cout<<"somvabona i "<<i<<" j "<<j<<endl;
            // mem(vis, -1)
            //     path = temp;
            //     // cout<<"pre_path "<<path<<endl;
            //     // if(str[i+1][j]<=str[i][j+1])
            //       generate(i+1, j);
            //     // else
            //     mem(vis, -1)
            //     path = temp;
            //       generate(i, j+1);
            //     // if((!ans.size()) || path<ans) {
                //   ans = path;
                // }
              Q.pb({i, j});
              // mnc = min(mnc, str[i][j]);
          }
        }
    }

    if(!Q.size()) {
      Q.pb({1,1});
      ans = str[1][1];
    }else
      ans = string(mxlen, 'a');

    // cout<<"init q_size "<<Q.size()<<endl;

    bfs();


    cout<<ans<<endl;


    return 0;
}
