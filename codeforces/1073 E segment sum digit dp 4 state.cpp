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



#define MX 20
#define double long double
#define mod 998244353
#define mod2 1000000009

ll pow10[50];
ll dp[30] [1<<11] [3] [3];
int ara[50];


bool possible(int pos, int mask, int len) {
    if(!mask)
        return true;
    int mn;
    for(int i=0; i<10; i++)
        if(CHECK(mask, i))
        {
            mn = i;
            break;
        }
    for(int i= pos; i<len; i++)
    {
        if(mn < ara[i])
            return true;
        if(mn>ara[i])
            return false;
    }
    return true;

}

// ll subsize[MX];
ll subsize[MX] [1<<11] [3];

ll rec(int pos, int mask, int first, int small, const int & len, const int & k) {
    // cout<<"pos "<<pos<<" mask "<<mask<<" small "<<small<<endl;
    // if(__builtin_popcount(mask)>k) {
    //     return -1e18;
    // }
    if(pos == len) {
        subsize[pos] [mask] [small]=1;
        return 0;
    }
    ll &ret = dp[pos] [mask] [first] [small];

    if(~ret)
        return ret;
    ret=0;
    // cout<<"aise";
    // int cnt=0;
    // subsize[pos]=0;
    for0(i, 10) {
        if(!small) {
            if(i>ara[pos])
                break;
        }

        if(__builtin_popcount(mask)==k) {
            if(!CHECK(mask, i))
                continue;
        }
        if(!small) {
            if(__builtin_popcount(mask)==k-1 && ( !CHECK(mask, i)) ) {
                if(!possible(pos, SET(mask, i), len) ) {
                    continue;
                }
            }
        }

        // if(__builtin_popcount(mask)==k && )
        //     continue;

        // if(rec(pos+1, SET(mask, i), small | (i<ara[pos]), len, k, sum+ (i*pow10[len-pos-1]))>0) {
        // cout<<"pos "<<pos<<" used "<<i<<"ara_pos "<<ara[pos]<<" added "<<(i* pow10[len-pos-1])<<endl;
            int next_mask;
            if(first && i==0) {
                next_mask=0;
            } else {
                next_mask = SET(mask, i);
            }
            ret+= rec(pos+1, next_mask, first & (i==0) , small | (i<ara[pos]), len, k);
            if(ret>=mod) {
                ret%=mod;
            }
            subsize[pos] [mask] [small]+= subsize[pos+1] [SET(mask, i)] [small | (i<ara[pos])];
            if(subsize[pos] [mask] [small]>=mod)
                subsize[pos] [mask] [small]%=mod;

            ll temp = (i* pow10[len-pos-1]);

            if(temp>=mod)
                temp %=mod;
            ret+= (subsize[pos+1] [SET(mask, i)] [small | (i<ara[pos])]* temp);

            if(ret>=mod) {
                ret%=mod;
            }
        // }
    }
    // cout<<"pos "<<pos<<" ret "<<ret<<endl;
    return ret;
}


bool valid(string s, int k) {
    set<char> sset;
    for(char i:s)
        sset.insert(i);
    return sset.size()<=k;
}

int main() {
    // FRE_IN_OUT
    // FRE_OUT
    pow10[0]=1;
    for1(i,40)
        pow10[i] = (pow10[i-1]*10)%mod;
    // for1(i,40)
    //     cout<<pow10[i]<<" "; cout<<endl;
    int len, k;

    string temp, temp2;
    ll val;
    cin>>val>>temp2>>k;
    stringstream ss;
    ss<<val;
    ss>>temp;

    len = temp.size();
    for0(i, len)
        ara[i] = (temp[i]-'0');
    // cout<<"len "<<len<<" k "<<k<<endl;
    // for0(i, len)
    //     cout<<ara[i]<<" "; cout<<endl;

    mem(dp, -1)
    mem(subsize, 0)

    ll l = rec(0, 0, 1, 0, len, k);
    // cout<<"L "<<l<<endl;
    // cout<<"aise"<<endl;


    len = temp2.size();
    for0(i, len)
        ara[i] = (temp2[i]-'0');

    mem(dp, -1)
    mem(subsize, 0)

    ll r = rec(0, 0, 1, 0, len, k);
    if(valid(temp, k)) {
        val%=mod;
    } else
        val=0;
    // if(temp==temp2) {
    //     cout<<val%mod<<endl;
    // }else
        cout<<((r+val-l)+mod)%mod<<endl;

    return 0;
}
