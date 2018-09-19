#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int kk[111], vis[1011], cnt[1011];
vector<int> conn [1011];
    int t, n, m ,k, u, v;


void dfs(int u, int col) {

    int len = conn[u].size();
    vis[u] = col;
    cnt[u]++;
    for(int i=0; i<len; i++) {
        if(vis[ conn[u][i] ]!= col) {
            dfs(conn[u][i], col);
        }
    }

}

int calc() {

    for(int i=1; i<=k; i++) {
        dfs(kk[i], i);
    }
    int ans=0;
    for(int i=1; i<=n; i++) {
        if(cnt[i]==k) ans++;
    }
    return ans;
}


int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);


    scanf("%d", &t);

    for(int tc=1; tc<=t; tc++) {
        for(int i=1; i<=n; i++) {
            cnt[i] = vis[i]=0;
            conn[i].clear();
        }
        scanf("%d %d %d", &k, &n, &m);

        for(int i=1; i<=k; i++) scanf("%d", &kk[i]);

        for(int i=0; i<m; i++) {
            scanf("%d %d",&u, &v);
            conn[u].push_back(v);
        }

        printf("Case %d: %d\n",tc, calc());



    }

    return 0;

}
