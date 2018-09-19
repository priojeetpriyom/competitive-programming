#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

//------------ loop macros

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)


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

#define sid(n, m) scanf("%d %lf", &n, &m);


#define scs(s) scanf("\n%s", s)
#define scss(s, ss) scanf("\n%s \n%s", s, ss)


//--------------output----------

#define pr printf
#define pri(n) printf("%d\n", n);
#define prl(n) printf("%lld\n", n);
#define prll(n, m) printf("%lld %lld\n", n, m);

// ------------- BIT MANIPULATION ------------

#define CHECK(n, pos) ( (n& (1<<pos))>0)
#define SET(n,pos) (n | (1<<pos))
#define RESET(n,pos) (n ^ (1<<pos))
#define mem(ara, val) memset(ara, val, sizeof ara);



//--------data structures
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdi pair<double, int>
#define pdl pair<double, ll>
#define pid pair<int, double>
#define pld pair<ll, double>

//--------others
#define SET_TIMER double timer =(double) clock();
#define PRINT_TIMER cout<<(clock()- timer)/CLOCKS_PER_SEC<<endl;





#define MX 200011
#define double long double
#define mod 1000000007
#define mod2 1000000009


ll dpnow[MX];
ll dplast[MX] ;

int func(int n) {
    return (n * (n+1))>>1;
}

//ll rec(int r, int len) {
////    cout<<"len "<<len<<" r "<<r<<" g "<<g<<endl;
//    if(!len)
//        return 1;
//    if(r<0)
//        return  0;
//    if(r> func(len))
//        return dp[r] [ len] = rec(r-1, len);
//    ll &ret = dp[r][len];
//
//    if(~ret)
//        return ret;
//
//    ret=0;
////    cout<<"aise"<<endl;
//    if(r>=len)
//        ret+= rec(r-len,len-1 );
//
////        ret = rec(r-1, len);
////    int g = ;
//    if(func(len) - r>=len && r<= func(len-1) )
//        ret+= rec(r, len-1);
//
//    return ret%=mod;
//}


int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    freopen("input.txt", "w", stdout);


//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    SET_TIMER

//    mem(dp, -1);
    int r, g, l;

    sii(r, g);

    l = r+g;

    int len=1;

    for(int i= 1; ; i++) {
        if(func(i)>l)
        {
            len = i-1;
            break;
        }

    }

//    cout<<"len "<<len<<endl;

//    ll ans=rec(r, len);
    ll ans= 0;
    for(int i=0; i<=2e5; i++)
        dplast[i] =1;
//    dplast[0]=1;
    for1(height, len) {
        for(int red=0; red<=r; red++) {
            dpnow[red]=0;
            int green = func(height) - red;
            if(green<0 || green>g)
                continue;
            if(red>=height)
                dpnow[red] += dplast[red-height];
            if(red<= func(height-1) && green>=height)
                dpnow[red]+= dplast[red];

            dpnow[red]%=mod;
//            cout<<"height "<<
        }
        for0(i, r+1)
            dplast[i] = dpnow[i];
    }


    for(int i=0; i<=r; i++)
        ans = (ans + dpnow[i])%mod;

    prl(ans);


//    PRINT_TIMER
    return 0;
}
