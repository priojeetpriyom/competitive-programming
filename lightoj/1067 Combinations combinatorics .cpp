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
#define mod 1000003
#define mod2 1000000009


ll big_mod(int n, int p) {
    if(!p)
      return 1;
    if(p==1)
      return n;

    ll ret = big_mod(n, p/2);
    if(ret>=mod)
      ret%=mod;
    ret = ret *ret;

    if(ret>=mod)
      ret%=mod;

    if(p&1) {
      ret*=n;
      if(ret>=mod)
        ret%=mod;

    }

    return ret;


}

ll fact[(int)1e6+5];


int main()
{

  // cout<<big_mod(2,10)<<endl;
//    FAST_READ

    int t;

    si(t);

    fact[0]=1;
    for1(i, 1e6) {
        fact[i] = (fact[i-1]* i);
        if(fact[i]>= mod)
          fact[i]%=mod;
    }

    for1(tc, t) {
        int n,k ;
        sii(n, k);
        ll ans;
        ans = fact[n];

        // cout<<n<<"! "<<ans<<endl;
        // cout<<k<<"! "<<fact[k]<<endl;
        // cout<<n-k<<"! "<<fact[n-k]<<endl;

        ans = ans * big_mod( (fact[k] * fact[n-k])%mod , mod-2);
        // cout<<"n!*k! "<<ans<<endl;
        if(ans>=mod)
          ans%=mod;
        // ans = fact[n];

        // ans = ans * big_mod(fact[n-k], mod-2);
        // if(ans>=mod)
        //   ans%=mod;

        pr("Case %d: %lld\n", tc, ans);
    }


    // getchar();
    // getchar();
    return 0;
}
