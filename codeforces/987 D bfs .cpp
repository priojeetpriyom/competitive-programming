
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100

vector<int> conn[MX], beg[MX];
int dist [MX] [110];

void bfs(int k) {
    queue<int> Q;
    for(auto i: beg[k]) {
        Q.push(i);
        dist[i] [k] = 0;
    }

    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();
//        int len = conn[cur].size();

        for(auto v: conn[cur]) {
            if(dist[v][k]== -1) {
                dist[v] [k] = dist[cur] [k] +1;
                Q.push(v);
            }
        }
    }

}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dist , -1, sizeof dist);
    int n, m ,k ,s;

    cin>>n>>m>>k>>s;

    int x;
    for(int i=1; i<=n; i++) {
        cin>>x;
        beg[x].push_back(i);
    }
    int u, v;
    for(int i=0; i<m; i++) {
        cin>>u>>v;
        conn[u].push_back(v);
        conn[v].push_back(u);
    }

    for(int i=1; i<=k; i++) {
        bfs(i);
    }

    for(int i=1; i<=n; i++) {
        nth_element(dist[i]+1, dist[i]+1+s, dist[i]+1+k);
    }

    for(int i=1; i<=n; i++) {
        ll sum=0;
        for(int j=1; j<=s; j++)
            sum+= dist[i][j];
        cout<<sum<<" ";
    } cout<<endl;





    return 0;
}


