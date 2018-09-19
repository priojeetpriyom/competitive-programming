#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int dist[500], conn[500][500];
int n=500,m;


void dfs(int u, int cost) {
    dist[u] = cost;
//    printf("u %d\n", u);
    for(int i=0; i<n; i++) {
        if(conn[u][i]!= (1<<30) && max(conn[u][i], cost) < dist[i]) {
//            printf("from cost %d to %d cost %d before %d\n", cost, i, conn[u][i], dist[i]);
//            getchar();
//            conn[u][i] = conn[i][u] = (1<<30)+1;
            dfs(i, max(cost, conn[u][i]));
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

    for(int tc=1; tc<=t; tc++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                conn[i][j] = 1<<30;
            }
            dist[i] = 1<<30;
        }
        scanf("%d %d", &n, &m);
        int u, v, d, s;
        for(int i=0; i<m; i++) {
            scanf("%d %d %d", &u, &v, &d);
            if(d < conn[u][v]) {
                conn[u][v] = conn[v][u] = d;
            }
        }
        scanf("%d", &s);
        printf("Case %d:\n", tc);
        dfs(s, 0);

        for(int i=0; i<n; i++) {
            if(dist[i] == (1<<30) )
                printf("Impossible\n");
            else printf("%d\n", dist[i]);
        }

    }



    return 0;

}
