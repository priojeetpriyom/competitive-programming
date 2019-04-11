#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 1010

vector<int> conn[MX];
int notLeaf[MX];
int vis[MX];


int ans=1;
void dfs(int cur, int par=-1) {
    if(vis[cur] || ans==-1)
        return;
    vis[cur]=1;
//    if(conn[cur].size()==1)
//        return;

    int cnt=0;
    for(auto v:conn[cur]) {
        dfs(v, cur);
        if(conn[v].size()==1)
            cnt++;
    }
    if(conn[cur].size()>1 && cnt<3)
    {
        ans=-1;
    }

    return;


}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n;

    cin>>n;
    int x;
    for(int i=2; i<=n; i++) {
        cin>>x;
        notLeaf[x]=1;
        conn[i].push_back(x);
        conn[x].push_back(i);
    }


    dfs(1);
    if(ans==-1)
        cout<<"No"<<endl;
    else
        cout<<"Yes"<<endl;


    return 0;
}


