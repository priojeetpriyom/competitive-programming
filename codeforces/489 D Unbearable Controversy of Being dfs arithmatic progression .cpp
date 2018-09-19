/*
    algo:
    idea:

*/
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 3030
#define mod 1000000007


ll calc(ll n,ll m,  ll mid) {
    ll ret=0;
    for(int i=1; i<=n; i++)
        ret += min(m, ((mid)/i));
//    cout<<"n "<<n<<" mid "<<mid<<" ret "<<ret<<endl;
    return ret;
}

vector<int> conn[MX];
ll ans=0;
int vis[MX], cnt[MX];
void dfs(int u, int depth) {
    if(depth==2) {
        cnt[u]++;
        return;
    }

    vis[u]=1;

    for(auto v : conn[u]) {
        {
            if(!vis[v]){
                dfs(v, depth+1);
            }
        }
    }

        vis[u]=0;

}

ll dhara(ll num) {
    if(num&1)
        return num * ((num+1)/2);
    else
        return (num/2) * (num+1);
}

ll solve() {

    int n, m;
    cin>>n>>m;
    int u,v;
    for(int i=0; i<m; i++) {
        cin>>u>>v;
        conn[u].push_back(v);
//        conn[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        memset(vis, 0, sizeof vis);
        memset(cnt, 0, sizeof cnt);
        dfs(i, 0);
//        cout<<"i "<<i<<": ";
//        for(int i=1; i<=n;  i++){
//            cout<<" "<<cnt[i];
//        } cout<<endl;

        for(int i=1; i<=n;  i++)
            if(cnt[i]>1)
                ans+= (dhara(cnt[i]-1));
    }


    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//freopen("output.txt", "w", stdout);
//    memset(dp, -1, sizeof dp);


    cout<<solve()<<endl;

    return 0;
}
