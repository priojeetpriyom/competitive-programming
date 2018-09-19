#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int vis[101], dist[101], ans[101];
vector <int> conn[101];


void bfs(int start) {

    queue<int> Q;
    Q.push(start);

    while(!Q.empty()) {
        int u = Q.front();Q.pop();
//        vis[u]=1;
        int len = conn[u].size();

        for(int i=0; i<len; i++) {
            int v = conn[u][i];
            if(!vis[v]) {
                vis[v]=1;
                dist[v] = dist[u] +1;
                ans[v]+= dist[v];
//                printf("v %d dist_v %d ans_v %d\n", v, dist[v], ans[v]);
                Q.push(v);
            }
        }
    }
}



int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);
    int t;
    scanf("%d", &t);

    int n=0,m, u, v;
    for(int tc=1; tc<=t; tc++) {
        for(int i=0; i<n; i++) {
            conn[i].clear();
            vis[i]=ans[i] = 0;
        }

        scanf("%d %d", &n, &m);

        for(int i=0; i<m; i++) {
            scanf("%d %d", &u, &v);
            conn[u].push_back(v);
            conn[v].push_back(u);
        }

        scanf("%d %d", &u, &v);
        dist[u]=0;vis[u]=1;
        bfs(u);
//        for(int i=0; i<n; i++) printf("%d ", ans[i]); printf("\n");
        memset(vis, 0, sizeof vis);
        dist[v]=0;vis[v]=1;
        bfs(v);

        int mx = -1;

        for(int i=0; i<n; i++)
            if(ans[i]>mx) mx = ans[i];

        printf("Case %d: %d\n",tc,  mx);

    }



    return 0;

}
