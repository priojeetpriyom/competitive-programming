#include <bits/stdc++.h>
using namespace std;

int n,m;
long long coins[800101];

struct node {
    int u,  cost;
};

vector<int> connection[800101];
int s,f;
long long cost[800101];
void bfs() {
    if(s==f)
    {
        cost[f]=0;
        return;
    }
    queue<struct node> Q;
    struct node cur;
    cur.u = s;
    cur.cost=0;

    Q.push(cur);

    while(!Q.empty()) {
        cur = Q.front();
        Q.pop();

        int len = connection[cur.u].size();

        for(int i=0; i<len; i++) {
            int v = connection[cur.u] [i];
            if(cur.cost+1 < cost[v]) {
                cost[v] = cur.cost+1;
                struct node newNode;
                newNode.cost = cur.cost+1;
                newNode.u = v;
                Q.push(newNode);
            }
        }
    }

}

int main()
{
//        freopen("myIn.txt", "r", stdin);
//    freopen("myOut.txt", "w", stdout);

    int t;
    cin>>t;

    for(int tc=1; tc<=t; tc++) {
        scanf("%d %d", &m, &n);

        for(int i=0; i<=n; i++)
        {
            cost[i] = INT_MAX;
            connection[i].clear();
        }

        for(int i=1; i<=n; i++)
            scanf("%lld", &coins[i]);
        int x,y;
        for(int i=0; i<m; i++) {
            scanf("%d %d",&x, &y);
            connection[x].push_back(y);
            connection[y].push_back(x);
        }
        scanf("%d %d",&s, &f);
//        for(int i=0; i<100; i++)
//            printf("%d ", cost[i]);
//        printf("\n");
        cost[s] = 0;
        bfs();

//        printf("coins %lld cost %lld\n s %d f %d\n", coins[f], cost[f],s,f);

        if(cost[f] == INT_MAX)
            printf("Case %d: Path not found\n",tc);
        else if(coins[f] < cost[f])
            printf("Case %d: Don't travel\n",tc);
        else
            printf("Case %d: %lld\n",tc, coins[f] - cost[f]);


    }


    return 0;
}






