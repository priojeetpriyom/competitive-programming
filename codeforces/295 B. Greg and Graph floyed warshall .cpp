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

#define scs(s) scanf("\n%s", s)
#define scss(s, ss) scanf("\n%s \n%s", s, ss)


//--------------output----------

#define pr printf
#define pri(n) printf("%d\n", n);

// ------------- BIT MANIPULATION ------------

#define CHECK(n, pos) ( (n& (1<<pos))>0)
#define SET(n,pos) (n | (1<<pos))
#define RESET(n,pos) (n ^ (1<<pos))



#define MX 505
#define double long double
#define mod 1000000007
#define mod2 1000000009


ll cost[MX] [MX], vis[MX], rem[MX], ans[MX];

int main()
{
//    double time = clock();
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

//    si(t)
    int n;

    cin>>n;

    for0(i, n)
        for0(j, n)
            cin>>cost[i][j];
//    for0(i, n){
//
//        for0(j, n)
//            cout<<cost[i][j]<<" ";
//        cout<<endl;
//    }

    for0(i, n)
        cin>>rem[i];

    for(int m = n-1; m>=0; m--) {
        int k = rem[m]-1;
        ll tot=0;
        vis[k]=1;
        for0(i, n) {
            for0(j, n) {
//                cout<<"i "<<i<<" j "<<j<<" cost_i_j "<<cost[i][j]<<"  cost[i][k]" <<cost[i][k]<<" cost[k][j] "<<cost[k][j]<<endl;

                if(cost[i][j] > cost[i][k]+cost[k][j])
                    cost[i][j] = cost[i][k]+cost[k][j];
                if(vis[i]&&vis[j])
                    tot+= cost[i][j];
            }
        }


        ans[m] = tot;
//        cout<<"k "<<k<<" ans "<<ans[m]<<endl;
    }

    for0(i, n)
        cout<<ans[i]<<" ";
    cout<<endl;

//    cout<<(clock()-time)/CLOCKS_PER_SEC;

    return 0;
}
