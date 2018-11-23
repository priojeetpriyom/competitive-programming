/*
    algo:
    idea:

*/

#include<bits/stdc++.h>
// #include <iostream>
// #include <string.h>
// #include <assert.h>

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
// inline void inp_int( int &n ){n=0;int ch=getchar_unlocked();int sign=1;while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}while(  ch >= '0' && ch <= '9' )n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();n=n*sign;}



#define MX 100100
// #define double long double
// #define MOD 1000000007
// #define MOD2 1000000009
#define BASE 31

ll pw[MX];
void init(int max_len) {
  pw[0]=1;
  for1(i, max_len){
      pw[i]= pw[i-1] * BASE;
      // if(pw[i]>=MOD)
      //   pw[i]%=MOD;
      // cout<<pw[i]<<" ";
  }
  // cout<<endl;
}
// ll big_mod(int n, int pw,ll mod) {
//   if(!pw)
//     return 1;
//
//   ll ret = big_mod(n, pw>>1, mod);
//   ret*=ret;
//   if(ret>=mod) ret%=mod;
//   if(pw&1)
//     ret*=n;
//
//   if(ret>=mod) ret%=mod;
//   return ret;
// }

ll ara[20][MX], hash_ara[20] [MX];
void build_hash_ara(int pos, int len) {

    for(int i=1; i<=len; i++) {
        // ll basepw = base* pw[i];
        // if(basepw>=MOD) basepw%=MOD;

        hash_ara[pos][i] = (hash_ara[pos][i-1]*BASE) + ara[pos][i];
        // if(hash_ara[i]>=MOD) hash_ara[i]%=MOD;
    }

}




ll get_hash_diff(int pos, int l, int r) {
  // cout<<"r "<<r<<" l "<<l<<" hash[r] "<<hash_ara[r]<<" hashl-1 "<<hash_ara[l-1]<<" pw "<<pw[r-l+1]<<endl;
  // ll lval = hash_ara[l-1]* pw[r-l+1];
  // // if(lval>=MOD) lval%=MOD;
  // ll ret = hash_ara[r] - lval;
  // if(ret<0)
  //   ret+=MOD;
  // if(ret>=MOD)
  //   ret-=MOD;

  // return ret;
  return hash_ara[pos][r]- ( hash_ara[pos][l-1]* pw[r-l+1]);
  // return ((hash_ara[r]- (( hash_ara[l-1]* pw[r-l+1]) %MOD)) +MOD)%MOD;

}

int position[20] [MX];

bool is_possible(int l, int r, int n, int m) {
  ll val= get_hash_diff(1, l, r);
  // cout<<"l "<<l<<" r "<<r<<" val "<<val<<endl;
  // int dist = r-l;
  for(int i=2; i<=m; i++) {
  //   int f=0;
  //   for(int j=1; j+dist<=n; j++) {
  //     if(get_hash_diff(i, j, j+dist) == val) {
  //       f=1;
  //       break;
  //     }
  //   }
  //   if(!f)
  //     return false;
    if(val != get_hash_diff(i, position[i] [ara[1][l]], position[i] [ara[1][r] ]))
      return false;
  }
  // // cout<<"l "<<l<<" r "<<r<<" possible "<<endl;
  return true;
  // return
}

int b_search(int low, int high, int n, int m) {
  int mid;
  int start = low;

  while(low<=high) {
    mid = (low+high)>>1;
    if(is_possible(start, mid, n, m))
      low = mid+1;
    else
      high = mid-1;
  }
  low = max (start, low-1);

  return low - start+1;
}



int main() {
    // FRE_IN_OUT
    // FRE_OUT
    // FAST_READ

    int n, m;
    // cin>>n>>m;
    sii(n, m)

    init(n);

    for1(i, m){
      for1(j, n)
      {
        sl(ara[i][j]);
        position[i][ ara[i][j] ] = j;
      }

        // cin>>ara[i][j];

      build_hash_ara(i, n);
      // for1(j,n)
      //   cout<<hash_ara[i][j]<<" ";
      // cout<<endl;
    }

    // cout<<is_possible(2, 3, hash_ara, n, m)<<endl; return 0;

    ll ans=0;

    for(int i=1; i<=n; i++) {
      int pos = b_search(i, n, n, m);
      // cout<<"i "<<i<<" pos "<<pos<<endl;
      ans+= pos;
    }

    // cout<<ans<<endl;
    prl(ans)




    return 0;
}
