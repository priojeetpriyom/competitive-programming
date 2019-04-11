#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n, color[200100];
vector<int> connection[200100];

void dfs(int pos, int par_col) {
//    printf("pos %d\n", pos);
    int len = connection[pos].size();

    int col=1;
    for(int i=0; i<len; i++) {
        int vis = connection[pos] [i];
        if(!color[vis]) {
//            printf("pos %d vis %d\n", pos, vis);
            while(col == color[pos] || col == par_col)
                col++;
            color[vis] = col++;
            dfs(vis, color[pos]);
        }
    }
//    path.pop_back();
}


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    cin>>n;

    int u,v;
    for(int i=1; i<n; i++) {
        scanf("%d %d", &u, &v);
        connection[u].push_back(v);
        connection[v].push_back(u);
    }
//    color[1]=1;

//path.push_back(1);
    for(int i=1; i<=n; i++) {
        if(connection[i].size() ==1 )
        {
            color[i]=1;
            dfs(i, 0);
            break;
        }
    }
    int mx =1;

    for(int i=1; i<=n; i++)
        mx = max(mx, color[i]);

    printf("%d\n", mx);

    for(int i=1; i<=n; i++)
        printf("%d ", color[i]);

    return 0;
}


