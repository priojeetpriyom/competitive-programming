#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 100100

int old[MX], ans[MX], toggle[MX];
vector<int> conn[MX];

void dfs(int u, int curToggle, int par) {
//    printf("u %d curTog %d tog[u] %d\n", u, curToggle, toggle[u]);
    ans[u] = (curToggle ^ toggle[u] ) ^ old[u];
    int len = conn[u].size();

    for(int i=0; i<len; i++) {
        int &v = conn[u][i];

        if(v != par) {
            dfs(v, curToggle^toggle[u], u);
        }
    }


}

int main()
{
//    freopen("myOut.txt", "w", stdout);
//    ios_base::sync_with_stdio(0);   cin.tie(0);

    int t, tc;
    scanf("%d", &t);

    for(tc=1; tc<=t; tc++) {
        int n, q;
        scanf("%d %d", &n, &q);
        for(int i=0; i<=n; i++)
        {
            conn[i].clear();
            toggle[i]=0;
        }
        for(int i=1; i<=n; i++) {
            scanf("%d",&old[i]);
        }
        for(int i=1; i<n; i++) {
            int u,v;
            scanf("%d %d", &u, &v);
            conn[u].push_back(v);
            conn[v].push_back(u);
        }
//        printf("aise\n");
        for(int i=1; i<=q; i++) {
            int x;
            scanf("%d", &x);
            toggle[x]^=1;
        }

        dfs(1, 0, -1);

        printf("Case %d:", tc);
        for(int i=1; i<=n; i++)
            printf(" %d", ans[i]);
        printf("\n");
    }




    return 0;
}

