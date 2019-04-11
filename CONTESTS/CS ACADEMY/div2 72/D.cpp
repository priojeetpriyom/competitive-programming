#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100
int conn[MX];

unordered_set<int> sset;
int vis[MX];
vector<pair<int, int> > pairs, ans;

void dfs(int u, int par) {
    if(par!= -1)
        pairs.push_back(make_pair(par, u));
    vis[u]=1;
    if(!vis[conn[u]])
        dfs(conn[u], u);

}


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n;

    cin>>n;

    for(int i=1; i<=n; i++)
        sset.insert(i);
//    printf("aise\n");
    for(int i=1; i<=n; i++)
    {
        cin>>conn[i];
        if(sset.find(conn[i])!= sset.end())
        sset.erase(sset.find(conn[i]));
    }
    if(!sset.size())
        sset.insert(1);
    for(auto u: sset) {
//        printf("u %d\n", u);
        if(!vis[u]) {
            dfs(u, -1);

            for(int i=pairs.size()-1; i>=0; i--) {
                ans.push_back(pairs[i]);
            }
            pairs.clear();

        }

    }
    for(int u=1; u<=n; u++) {
        if(!vis[u]) {
            dfs(u, -1);

            for(int i=pairs.size()-1; i>=0; i--) {
                ans.push_back(pairs[i]);
            }
            pairs.clear();

        }
    }

    for(auto a: ans)
        cout<<a.first<<" "<<a.second<<endl;

    return 0;
}


