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



#define MX 1001000
#define double long double
#define mod 100000007
#define mod2 1000000009

ll ara[20];
// ll ncr[1000115] [20];
ll fact[MX];

int l[20], r[20], d[20];


ll big_mod(ll n, ll pw) {

  if(pw==0)
    return 1;

  ll ret = big_mod(n, pw/2);

  ret*=ret;
  if(ret>=mod)
    ret%=mod;

  if(pw&1)
    ret*=n;


    if(ret>=mod)
      ret%=mod;

    return ret;

}


ll NCR(int n, int r) {

    // cout<<"called n "<<n<<" r "<<r<<endl;
  if(n<r)
    return 0;
  if(n==r)
    return 1;
  if(r==1)
    return n;
  if(r==0)
    return 1;


  ll ret = fact[n];

  ret = ret * big_mod((fact[r]*fact[n-r])%mod, mod-2);

  // cout<<"n "<<n<<" r "<<r<<" fact[n] "<<fact[n]<<" ret "<<ret<<endl;
  if(ret>=mod)
    ret%=mod;


  return ret;

}

int main()
{
  // FRE_IN_OUT

    fact[0]=1;

    for1(i, MX-1)
    {
      fact[i] = fact[i-1] *i;
      if(fact[i]>=mod)
        fact[i]%=mod;
      // cout<<"i "<<fact[i]<<endl;
    }


    int t;

    si(t)

    int k, n;

    for1(tc, t) {

      sii(k, n)

      for0(i, k){
        sii(l[i], r[i])
        // if(tc == 14)
        //   cout<<l[i]<<" "<<r[i]<<endl;
      }

      int lim = n;

      for0(i, k)
        lim-= l[i];


      // int tot=0;

      int dept=0;
      for0(i, k) {
          d[i] = r[i] - l[i];
          // tot+= d[i];
          dept+= (d[i]>=0);
      }

      ll ans = (lim? 0: 1);
          // cout<<"aise lim "<<lim<<" dept "<<dept<<endl;
      ans= NCR(lim+dept-1, dept-1);
      // cout<<" lim "<<lim<<" ans "<<ans<<endl;

      for1(i, (1<<k)-1) {
          int type = (__builtin_popcount(i)&1 ? -1: 1);
          ll temp =0;

          for(int j=0; j<15; j++) {
              if(CHECK(i, j)) {
                  // if(d[j])
                  {
                    temp+= d[j]+1;
                    // if(i==16) {
                    //   cout<<"\n\nj "<<j<<" d[j] "<<d[j]<<endl;
                    // }
                  }
                  // if(temp>=mod)
                  //   temp%=mod;
              }
          }
          int t2 = temp;
          if(temp) {
            temp = NCR( (lim- temp) +dept -1, dept-1);
            ans+= (type * temp);
            if(ans>=mod || ans<0) {
              ans = (ans+mod)%mod;
            }

          }

                    // cout<<"i "<<i<<" type "<<type<<" val "<<t2<<" ans "<<ans<<endl;
      }

      ans%=mod;


      PRINT_LOJ_TC
      prl(ans)

        // pr("finished");

    }
    return 0;
}
