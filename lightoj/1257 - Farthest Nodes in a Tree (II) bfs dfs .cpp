///for every node in a tree the farthest node will be one of the two most farthest node of that tree.



#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 30010


int n;

vector<pair<int, int> > conn[MX];
int dist1[MX], dist2[MX];

int mx, farthestNode;

int bfs(pair<int, int> start, int dist[])
{
    int vis[MX];
    memset(vis, 0, sizeof vis);
    queue<pair<int, int> > Q;
    Q.push(start);

    while(!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        int & u = cur.first;
        int & d = cur.second;
        if(vis[u])
            continue;
        vis[u]=1;
        dist[u] = d;
        if(d>mx) {
            mx = d;
            farthestNode = u;
        }
        for(int i=0; i<conn[u].size(); i++) {
            Q.push({conn[u][i].first, d+ conn[u][i].second});
        }

    }


//    return -1;

}



int main()
{
//    cout<<-13%5;
//    freopen("out.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    ios_base::sync_with_stdio(false);
//    cin.tie(false);

    int t;
    scanf("%d", &t);
    for(int tc=1; tc<=t; tc++)
    {
//        memset(cnt, 0, sizeof cnt);
//        memset(dist1, 0, sizeof dist1);
//        memset(dist2, 0, sizeof dist2);

        scanf("%d", &n);
        for(int i=0; i<n; i++)
            conn[i].clear();

        for(ll i=1; i<n; i++)
        {
            int u, v, d;
            scanf("%d %d %d", &u, &v, &d);
            conn[u].push_back({v,d});
            conn[v].push_back({u,d});
        }
        mx=0;
        bfs({0,0}, dist1);
//        printf("farthest1 %d\n", farthestNode);

        mx=0;
        memset(dist1, 0, sizeof dist1);
        bfs({farthestNode, 0}, dist1);

//        for(int i=0; i<n; i++)
//            printf("%d ", dist1[i]);
//        printf("\n");
//        printf("farthest2 %d\n", farthestNode);

        mx=0;
        memset(dist2, 0, sizeof dist2);
        bfs({farthestNode, 0}, dist2);

//        for(int i=0; i<n; i++)
//            printf("%d ", dist2[i]);
//        printf("\n");

        printf("Case %d:\n", tc);
        for(int i=0; i<n; i++) {
            printf("%d\n", max(dist1[i], dist2[i]));
        }

    }



    return 0;
}


