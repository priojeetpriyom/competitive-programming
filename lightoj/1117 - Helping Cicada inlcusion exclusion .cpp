/*
    algo:
    idea:

*/
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 100100
#define mod 1000000007


ull ara[20];
vector<int> vec[1<<15];

ll solve() {

    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
        cin>>ara[i];
    ll ans = n;
//    int pos;
    for(int i=1; i<(1<<m); i++) {
        ull lcm=1;
        for(int j=0; j<vec[i].size(); j++) {
//            pos = vec[i][j];
                lcm = (lcm* ara[vec[i][j]])/ __gcd(lcm, ara[vec[i][j]]);
        }
//        cout<<"i "<<i<<" lcm "<<lcm<<endl;
        ans = ans + (n/lcm)*(__builtin_popcount(i)%2==1? -1:1);
    }

    return ans;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    memset(dp, -1, sizeof dp);

    int t=1;
    cin>>t;

    for(int i=1; i<(1<<15); i++) {
        ull lcm = 1;
        for (int j = 0; j < 32; j++) {
            if (i & (1 << j)) {
                vec[i].push_back(j);
            }
        }
    }

    for(int tc=1; tc<=t; tc++) {

//        cout<<"Case #"<<tc<<": ";
        cout<<"Case "<<tc<<": ";
        cout<<solve()<<endl;
//    printf("%lld\n", solve());
    }

    return 0;
}
