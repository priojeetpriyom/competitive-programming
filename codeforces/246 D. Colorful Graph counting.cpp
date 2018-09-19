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

vector<int> conn[MX], col(MX);
map<int, set<int> > mp;
ll solve() {

    int n, m;
    cin>>n>>m;

    for(int i=1; i<=n; i++) {
        cin>>col[i];
        mp[col[i] ];

    }

    for(int i=0; i<m; i++) {
        int u,v;
        cin>>u>>v;
        conn[u].push_back(v);
        conn[v].push_back(u);
    }

    int mx=0, ans=(*mp.begin()).first;

    for(int i=1; i<=n; i++) {
        for(auto v : conn[i]) {
            if(col[i]!=col[v])
            mp[col[i]].insert(col[v]);
        }
//        if(conn[i].size()==0 && ans==1) {
//            ans = col[i];
//        }
    }

    for(auto it: mp) {
        if(it.second.size()>mx) {
            mx = it.second.size();
            ans = it.first;
        }
//        cout<<"col "<<it.first<<" size "<<it.second.size()<<endl;
    }
//    cout<<"mx "<<mx<<endl;
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
//    cin>>t;

    for(int tc=1; tc<=t; tc++) {

//        cout<<"Case #"<<tc<<": ";
        cout<<solve()<<endl;
//    printf("%lld\n", solve());
    }

    return 0;
}
