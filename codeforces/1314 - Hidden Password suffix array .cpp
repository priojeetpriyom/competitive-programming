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

#define CHECK(n, pos) ( (n& (1<<pos))>0)
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
#define pb push_back
#define mp make_pair
#define log2ceil(n) ( (ll) ceil(log2(n)))
#define pow2(n) (1<<n)


#define MX 200100
#define double long double
#define mod 1000000007
#define mod2 1000000009


struct node {
    int pos;
    int ri,rii;
};
int lim = log2ceil(MX);
int ranks[log2ceil(MX)+5][MX];
node L[MX];

bool cmp(node a, node b) {
    return a.ri==b.ri ? (a.rii<b.rii) : (a.ri<b.ri);
}

int build_suffix_ara(char str[], int len) {
    if(len<=1)
        return 1;

    for(int i=1; i<=len; i++)
    {
//        ranks[0][i].pos = i;
//        ranks[0][i].ri = str[i]-'a';
//        ranks[0][i].rii = str[i]-'a';
        ranks[0][i] = str[i]-'a';
    }

    lim = log2ceil(len);

    for1(step, lim) {
        for1(i, len) {
            L[i].pos = i;
            L[i].ri = ranks[step-1] [i];
            L[i].rii = (i+ pow2(step-1) <=len ? ranks[step-1] [i+pow2(step-1)] : 10000000);
        }
        sort(L+1, L+len+1, cmp);

//        for1(i, len) {
//            auto l = L[i];
//            cout<<l.pos<<" ";
//        }
//        cout<<"after_sort"<<endl;

        for1(i, len) {
            ranks[step] [L[i].pos] = ( (i>1 && L[i].ri == L[i-1].ri && L[i].rii==L[i-1].rii)? ranks[step] [L[i-1].pos] : i);
        }
    }

//    for1(i, len) {
//        cout<<"pos "<<L[i].pos<<" rank "<<ranks[lim] [L[i].pos]<<" "<<str+ L[i].pos<<endl;
//    }

    return L[1].pos;

}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    freopen("input.txt", "w", stdout);


//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    SET_TIMER


    int t;

    si(t);

    char str[MX];


    while(t--) {
        int len;
        si(len) scs(str+1)

        for1(i, len)
            str[i+len] = str[i];
        len+=len;

        int pos = build_suffix_ara(str, len);

        pri(pos-1)
    }


//    cout<<ans<<endl;

//    PRINT_TIMER
}
