#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int vis[20100];
vector<int> conn[20100];

void dfs(int u, int col) {
//    printf("u %d col %d\n", u, col);
    int f=1, len = conn[u].size();
    vis[u] = col;

    if(col&1) col++;
    else col--;

    for(int i=0; i<len; i++) {
        if(!vis[conn[u][i] ]) dfs(conn[u][i], col);
    }


}




int calc() {
    int col =1, col_cnt[20010];
    for(int i=1; i<=20000; i++) {
        if(!vis[i] && conn[i].size()) {
            dfs(i, col);
            col+=2;
        }
        col_cnt[i]=0;
    }

    for(int i=1; i<=20000; i++) {
        col_cnt[vis[i] ]++;
    }
    int ans=0;
    for(int i=1; i<=20000; i+=2) {
        ans+= max(col_cnt[i], col_cnt[i+1]);
    }

    return ans;

}


int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t, n=0, u,v;
    scanf("%d", &t);

    for(int tc=1; tc<=t; tc++) {
        for(int i=0; i< 20100; i++) {
            conn[i].clear();
            vis[i]=0;
        }
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d %d", &u, &v);
            conn[u].push_back(v);
            conn[v].push_back(u);
        }

        printf("Case %d: %d\n",tc, calc());



    }


    return 0;

}

