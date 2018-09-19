#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define MX 111
#define double long double
#define mod 1000000007
#define mod2 1000000009
#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)

#define cin0(n, ara) for(int i=0; i<n; i++) {cin>>ara[i];}
#define cini0(i, n, ara) for(int i=0; i<n; i++) {cin>>ara[i];}

#define cin1(n, ara) for(int i=1; i<=n; i++) {cin>>ar[i];}
#define cini1(i, n, ara) for(int i=1; i<=n; i++) {cin>>ar[i];}


ll hasht, pw, base=257;
int n, cnt[MX], dp[MX];
vector<int> vec;
set<int> divs[MX];

int r[MX], c[MX], ans[MX] [MX];
int main()
{

    double time = clock();
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    freopen("input.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

//    memset(dp, -1, sizeof dp);


//    cout<<1e5<<endl;
//
//    for(int i=1; i<=1e5; i++)
//        cout<<i<<" ";
//    cout<<endl;


    int n, m;
    cin>>n>>m;

    cin0(n, r);
    cin0(m, c);
    int rr=0, cc=0;
    for0(i, n)
        rr ^= r[i];

    for0(j, m)
        cc ^= c[j];

    if(rr!= cc) {
        cout<<"NO"<<endl;
        return 0;
    }

//    for0(i, n) {
        for0(j, m) {
          if(j==0) {
//              cc ^=c[0];
              ans[0][0] = r[0];
              for1(i, m-1)
              {
                  ans[0][0] ^= c[i];
//                  cout<<"c "<<i<<" ans[0][0] " <<ans[0][0]<<endl;
              }
          }else
          {
              ans[0][j] = c[j];
          }
//        }
    }

    for1(i, n-1)
        ans[i][0] = r[i];

    cout<<"YES"<<endl;
    for0(i, n) {
        for0(j, m)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }



//    cout<<(clock()-time)/CLOCKS_PER_SEC<<endl;

    return 0;
}
