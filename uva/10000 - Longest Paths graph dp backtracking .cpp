#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int conn[101][101], dist[101], dir[101], conn2[101] [101];

    int n, start;
int dfs(int u) {
//    printf("u %d d %d par %d\n",u,d,par);
    int &ret = dist[u];
    if(ret!= -1) return ret;
//    printf("u %d\n", u);
    ret=0;
    for(int i=1; i<=n; i++) {
        if(conn[u][i] ) {
            conn[u][i] = conn[i][u]=0;
            int x = dfs(i)+1;
            if(x>ret) {
                ret = x;
                dir[u] = i;
            }
//            conn[u][i] = conn[i][u]=1;
        }
    }
    return ret;
}

int get_farthest_node(int u, int d) {
//    printf("u %d d %d\n",u,d);
    if(d==0) {
        return u;
    }
    int x = INT_MAX;
    for(int i=1; i<=n; i++) {
        if(dist[i] == d-1 && conn2[u][i]) {

            x = min(x, get_farthest_node(i, d-1));
        }
    }
    return x;
}


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int tc=1;
    while(scanf("%d", &n)==1 && n!=0) {
        memset(conn, 0, sizeof conn);
        memset(conn2, 0, sizeof conn2);
        memset(dist, -1, sizeof dist);
        scanf("%d",&start);
        int u, v;
        while(scanf("%d %d",&u, &v)==2 && u!=0) {
            conn[u][v]=conn2[u][v]=1;
        }
//        dist[start]=0;
        int mx = dfs(start);

        int mx_node = get_farthest_node(start, mx);
        for(int i=1; i<=n; i++) {
            if(dist[i]>mx) {
                mx = dist[i];
                mx_node = i;
            }
//            dist[i]=0;
        }
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",tc++,start,mx,mx_node);
    }


    return 0;
}




