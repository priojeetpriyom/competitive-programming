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

set<int> conn[MX], going;
int cnt[MX];
vector<pii> query(MX);
int vis[MX];
queue<int> useless;

int n, m , k;
int ans[MX];

void calc_useless() {

    while(!useless.empty()) {
        int cur = useless.front();
        useless.pop();
//        if(going.find(cur)!= going.end())
//            continue;

        for(int v: conn[cur]) {
            cnt[v]--;
            if(cnt[v]<k && going.find(v)!= going.end()) {
                going.erase(going.find(v));
                useless.push(v);
            }
            conn[v].erase(conn[v].find(cur));
        }
    }

}
void make_useless() {

    while(!useless.empty()) {
        int cur = useless.front();
        useless.pop();
//        if(going.find(cur)!= going.end())
//            continue;
//        cnt[cur]-=
        for(int v: conn[cur]) {
            cnt[v]--;
            if(cnt[v]<k && going.find(v)!= going.end()) {
                going.erase(going.find(v));
                useless.push(v);
            }
            conn[v].erase(conn[v].find(cur));
        }
    }

}

int main()
{

//    mset.insert(1);
//    mset.insert(1);
//    mset.insert(1);
//    mset.insert(1);
//    mset.insert(5);
//    mset.erase(mset.begin());

//    for(auto m: mset)
//        cout<<m<<endl;



//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    freopen("input.txt", "w", stdout);
//    cout<<1000<<" "<<1000<<" "<<1000000<<" "<<100<<endl;
//
//    for1(i, 1000)
//    {
//        for1(j, 1000) {
//            cout<<"1 ";
//        }
//        cout<<endl;
//    }
//    exit(0);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    SET_TIMER


    cin>>n>>m>>k;


//    for1(i, n) {
//        going.insert(i);
//    }
    int u, v;
    for1(i, m) {
//        pii p;
        cin>>u>>v;
        query[i] = make_pair(u, v);
        conn[u].insert(v);
        conn[v].insert(u);
        cnt[u]++;
        cnt[v]++;
    }


    for1(i, n) {
        if(cnt[i]<k) {
            useless.push(i);
        } else
            going.insert(i);
    }

    calc_useless();

    ans[m] = going.size();
    for(int i = m; i>0; i--) {

//        for1(j, n)
//            cout<<cnt[j]<<" ";
//        cout<<endl;
//        for(int j : going)
//            cout<<j<<" ";
//        cout<<endl;

        u = query[i].first;
        v = query[i].second;
        cnt[u]--;
        cnt[v]--;
        if(cnt[u]<k && cnt[v]<k && going.find(u)!=going.end()  && going.find(v) != going.end()) {
            going.erase(going.find(u));
            useless.push(u);
//            calc_useless();
            going.erase(going.find(v));
            calc_useless();
        }
//        if() {
//        }

        ans[i-1] = going.size();

    }


    for1(i, m)
    cout<<ans[i]<<endl;




//    PRINT_TIMER
}
