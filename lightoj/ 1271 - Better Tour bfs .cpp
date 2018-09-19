#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 50010
//#define mod 1000000007

int dist[MX];
//int vis[MX];
int t, tc;
vector<int> conn[MX];
int path[MX], len;
int f;

void dfs(int u, int d)
{
//    printf("u %d\n",u);

//    int &ret = dist[u];
//    if(~ret)
//        return ret;
//    printf("aise\n");
//    ret = 1e9;
//    vis[u]=1;
//    dist[u]=d;
queue<int> Q;
    Q.push(u);
//    vis[u]=1;
    dist[u]=0;
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();


        if(u==f)
        {
//            dist[u]=d;
//            while(!Q.empty())
//                Q.pop();
            return;
        }
//    printf("conn_%d_size %d\n",u, conn[u].size());
        for(int i=0; i< conn[u].size(); i++)
        {
//        printf("i %d conn_u_i %d dist_conn_u_i %d\n",i,conn[u][i], dist[conn[u][i] ]);
//        if() {
            int &x = conn[u][i];
            if(dist[x]== (1<<30))
            {
//                vis[x]=1;
                dist[x] = dist[u]+1;
                Q.push(x);
            }
//        }
        }
    }
//    vis[u]=0;
//    if(ret==1e9)
//    {
//        ret =-1;
//        return 1e9;
//    }
//    return ret;
//    dist[u] = 0;
}

void find_path(int u)
{
    while(1)
    {
//    printf("find u %d\n", u);
//    getchar();
        if(u==f)
        {
//            ans = path;
            return;
        }
        int mn = 1e9, v=1e9;

        for(int i=0; i<conn[u].size(); i++)
        {
            int &x = conn[u][i];
            if(dist[x]<mn || (dist[x]==mn && x < v))
            {
                mn = dist[x];
                v = x;
            }
        }
        path[len++] = v;

        u=v;
    }
//    find_path(v);


}

int main()
{
//freopen("output.txt", "w", stdout);

//    process[0]= {1,2,3};

//    cout<<process[0].id<<" "<<process[0].at<<" "<<process[0].bt<<endl;

    scanf("%d", &t);
//    memset(ncr, -1, sizeof ncr);
//    memset(dp, -1, sizeof dp);
    int n,x, y, mx=0;
        for(int i=1; i<MX; i++)
        {
            dist[i] = 1<<30;
        }
    for( tc=1; tc<=t; tc++)
    {
    len=0;
//        memset(dist, -1, sizeof dist);
//        memset(vis, 0, sizeof vis);
//        int n;
        int start;
        scanf("%d %d", &n, &start);

//        ans.clear();
//        path.clear();
        for(int i=1; i<=mx; i++)
        {
            conn[i].clear();
            dist[i] = 1<<30;
        }
//        len=0;
        x = start;
        mx= x;
//        n--;
        for(int i=1; i<n; i++)
        {
            scanf("%d", &y);
            if(y>mx)
                mx=y;
            conn[x].push_back(y);
            conn[y].push_back(x);
            x=y;
//            printf("%d %d\n",x, len);
        }

        path[len++] = start;
//        printf("aise n %d\n", n);
        f=start;
        dfs(y, 0);
//        for(int i=1; i<=n; i++)
//            printf("%d ", dist[i]);
//            printf("\n");
//        printf("bfs oka\n");
        f=y;
        find_path(start);
        printf("Case %d:\n", tc);
        for(int i=0; i<len-1; i++)
            printf("%d ", path[i]);
        printf("%d\n", path[len-1]);
    }
//    printf("\n");


    return 0;
}
