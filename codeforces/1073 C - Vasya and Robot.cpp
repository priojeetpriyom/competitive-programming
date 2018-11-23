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

char str[MX];

ll cumx[MX], cumy[MX];
ll goalx, goaly;
int n;
ll mncost = 1e9;

ll calc(int start, ll x, ll y) {
    x+= (cumx[n] - cumx[start]);
    y+= (cumy[n] - cumy[start]);
    return abs(goalx - x) + abs(goaly - y);
}


ll b_search(int low, int high, ll prefx, ll prefy) {

    ll start = low;
    ll mid;
    ll ret = 1e9;
    while(low<=high) {
        mid = (low+high)>>1;
        ll cost = calc(mid, prefx, prefy);
        // cout<<"start "<<start<<" mid "<<mid<<" cost "<<cost<<endl;
        if(cost <= mid-start+1 && (mid-start+1 - cost)%2==0) {
            high = mid-1;
            ret = min(ret, mid-start+1);
        } else
            low = mid+1;
    }

    // high = min(n, high+1);

    return ret;

}

int main()
{
//    FAST_READ

    // int n;
    cin>>n;

    cin>>str+1;

    cin>>goalx>>goaly;

    if(abs(goalx)+abs(goaly)>n || ((n - abs(goalx)+abs(goaly)) &1) ) {
      cout<<-1<<endl;
      return 0;
    }

    for1(i, n) {
      cumx[i] = cumx[i-1];
      cumy[i] = cumy[i-1];

      if(str[i]=='U' || str[i]=='D') {
        cumy[i]+= (str[i]=='U'?1: -1);
      } else {
        cumx[i]+= (str[i] == 'R'? 1: -1);
      }
    }

    if(cumx[n] == goalx && cumy[n] == goaly) {
        cout<<0<<endl;
        return 0;
    }
    // for1(i, n) {
    //     cout<<cumx[i]<<", "<<cumy[i]<<endl;
    // }

    ll ans = 1e9;
    for1(i,n) {
        ll ret = b_search(i, n, cumx[i-1], cumy[i-1]);
        ans = min(ans, ret);
        // cout<<"i "<<i<<" ret "<<ret<<endl;
    }



    cout<<(ans==1e9? -1: ans)<<endl;


    return 0;
}
