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



#define MX 10010
#define double long double
#define mod 100000007
#define mod2 1000000009

ll ara[MX];
ll ncr[MX] [10], dp[MX], calc[MX];


ll NCR(int n, int r) {
    if(n<r)
      return 0;
    if(n==r)
      return 1;
    if(r==1)
      return n;

    ll &ret = ncr[n][r];

    if(~ret)
      return ret;

    ret = NCR(n-1, r) + NCR(n-1, r-1);

    // if(ret>= mod)
    //   ret%= mod;

    return ret;

}

int n;

void pre_calc(int mx) {


  int root = sqrt(mx);

  for1(i, root) {
    for1(j, n) {
        if(ara[j]%i==0) {
          calc[i]++;
          if(ara[j]/i > root)
            calc[ara[j]/i]++;
        }
    }
  }

  // for1(i, mx)
  //   cout<<calc[i]<<" ";
  //   cout<<endl;

  for1(i, mx){
    assert(calc[i]<=1e4);
      calc[i] = NCR(calc[i], 4);
  }



      // for1(i, mx)
      //   cout<<calc[i]<<" ";
      //   cout<<endl;


}



int main()
{
    mem(ncr, -1)


  // cout<<NCR(4,3)<<endl;
  // return 0;
  // cout<<big_mod(2,10)<<endl;
//    FAST_READ

  // FRE_IN_OUT

  // cout<<"aise\naise\n";


    int t;

    si(t)


    for1(tc, t) {
      mem(dp, 0)
      mem(calc, 0)

      si(n)
      ll mx=0;
      for1(i, n){

          sl(ara[i]);
          mx = max(mx, ara[i]);
          // cout<<"i "<<i<<endl;

      }



      pre_calc(mx);

      frr(i, mx, 1) {
        dp[i] = calc[i];

        for(int j = i+i; j<=mx; j+=i) {
          dp[i]-= dp[j];
        }
      }



      PRINT_LOJ_TC
      prl(dp[1])

        // pr("finished");

    }
    return 0;
}
