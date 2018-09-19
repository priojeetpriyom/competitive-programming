
#include <bits/stdc++.h>
using namespace std;

vector<int> connection[1000];
int n, m;
int level[1000];
int par [1000] [12];
bool visited[1000];
int dfs(int curNode, int lvl) {
    level[curNode] = lvl;
    int len = connection[curNode].size();
    visited[curNode] = true;

    for(int i=0; i<len; i++) {
        if(!visited[connection[curNode] [i]]) {
            int x = dfs(connection[curNode] [i], lvl+1);
            par[x] [0] = curNode;

        }
    }
    return curNode;
}


void build_sparse_table() {
    printf("oka\n");
    memset(visited, 0, sizeof(visited));
    dfs(1, 1);
    for(int i = 1; i<11; i++)
        printf("%d ",level[i]);
    printf("\n");
    par[1] [0] = -1;
        for(int j=1; j<11; j++) {
            for(int i=1; i<=n; i++) {
                if(par[i] [j-1] != -1)
                    par[i] [j] = par[par[i] [j-1]] [j-1];
        }
    }
}

int findLog(int n) {
    int cnt=0;
    while(n>0)
    {
        cnt++;
        n>>=1;
    }
    return cnt;
}

int matchLevel(int u, int v) {
    int lim = findLog(u-v);

    for(int i= lim; i>=0; i--) {
        if(par[u][i]!= -1 && level[par[u][i] ] >= level[v])
            u = par[u] [i];
    }
    return u;
}

int findLca(int u, int v) {
    if(level[u] > level[v])
        u = matchLevel(u,v);
    else if(level[v] > level[u])
        v= matchLevel(v, u);

    int lim = findLog(level[u]);
    for(int i=lim; i>=0; i--) {
        if(par[u][i] != -1 && par[v] [i]!=-1 && par[u][i] != par[v][i] )
        {
             u = par[u][i];
             v= par[v] [i];
        }
    }
    return par[u] [0];
}

int main()
{
//    freopen("myOut.txt", "w", stdout);
    cin>>n>>m;
    int u,v, d;
    memset(par, -1, sizeof(par));
    for(int i=0; i<m; i++)  {
        scanf("%d %d", &u, &v);
        connection[u].push_back(v);
        connection[v].push_back(u);
    }
    build_sparse_table();

    printf("oka\n");
    while(scanf("%d %d", &u, &v)==2) {
        cout<<findLca(u,v)<<endl;
    }
    return 0;
}
