/*
  tutorial: http://codeforces.com/blog/entry/61323

*/




#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

//------------ loop macros

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define fr(i,start, till) for(int i=start; i<=till; i++)


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


#define scs(s) scanf("\n%s", s)
#define scss(s, ss) scanf("\n%s \n%s", s, ss)


//--------------output----------

#define pr printf
#define pri(n) printf("%d\n", n);
#define prl(n) printf("%lld\n", n);
#define prll(n, m) printf("%lld %lld\n", n, m);
#define prd(n) printf("%lf\n", n);
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





#define MX 707
#define double long double
#define mod 1000000007
#define mod2 1000000009

int ara[MX];
//int gcds[MX];
int dp[MX] [MX] [5];
int vis[MX];
vector<int> conn[MX];

int rec(int l, int r, int par_dir) {
//    cout<<"l "<<l<<" r "<<r<<" par_dir "<<par_dir<<" up "<<((par_dir)? ara[l-1] : ara[r+1])<<endl;
    if(r<l) {
        return 1;
    }
    int &ret = dp[l] [r][par_dir];

    if(~ret)
        return ret;

    int up = (par_dir? l-1 : r+1);
    ret=0;
    int len = conn[up].size()-1;
//    cout<<"roots: ";
//    fr(i, 0, len){
//        int root = conn[up][i];
//        if(root>=l && root<=r) {
//            cout<<root;
//        }
//    }cout<<endl;


    fr(i, 0, len){
        int root = conn[up][i];
        if(root>=l && root<=r) {
//            vis[root]=1;
            ret = ret | (rec(l, root-1, 0) & rec(root+1, r, 1));
            if(ret)
                return ret;
//            vis[root]=0;
        }
    }

    return ret;

}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    freopen("input.txt", "w", stdout);


//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    SET_TIMER

    mem(dp, -1)

    int n;

    si(n);

    for1(i, n)
        si(ara[i]);

    for1(i, n) {
//        cout<<ara[i]<<"=>";
        fr(j, 1, n) {
            if(j!=i && __gcd(ara[i], ara[j])>1) {
                conn[i].push_back(j);
//                cout<<j<<" ";
            }
        }
//        cout<<endl;
    }

//    fr(i, 1, n)
//        cout<<gcds[i]<<" ";
//
//    int twos=0, ones=0;

//    fr(i, 1, n) {
//        if(!gcds[i]) {
//            cout<<"No"<<endl;
//            return 0;
//        }
//        if(gcds[i]==1)
//            ones++;
//        else
//            twos++;
//
//    }

//    if(twos+1 >= ones || (n==2 && ones==2))
//        cout<<"Yes"<<endl;
//    else
//        cout<<"No"<<endl;
    int ans=0;
    for(int i=1; i<=n; i++ ){
//        vis[i]=1;
        ans = ans | (rec(1, i-1, 0) & rec(i+1, n, 1));
//        cout<<"i "<<i<<" ans "<<ans<<endl;
//        vis[i]=0;
        if(ans)
            break;
    }

    prs((ans? "Yes":"No"));

//    PRINT_TIMER
    return 0;
}
