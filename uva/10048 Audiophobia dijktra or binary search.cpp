#include<bits/stdc++.h>
using namespace std;
vector<int> connection[111], dist[111];
int visited[111];
bool comp(int a, int b)
{

    return a>b;
}

struct node
{
    int u,cost;


    bool operator<(const node& a) const
    {
        return cost>a.cost;
    }
};

int bfs(int u, int v, int lim)
{
//    queue<int> Q;
    priority_queue<node> Q;
    memset(visited, 0,sizeof visited);
    struct node cur;
    cur.cost =0;
    cur.u = u;
    Q.push(cur);

    int mx = -1;

    while(!Q.empty())
    {
        cur = Q.top();
//        printf("current node %d cost %d\n", cur.u, cur.cost);
        Q.pop();
        visited[cur.u] = 1;
        mx = max(mx, cur.cost);
        if(cur.u ==v)
            return mx;
        int len = connection[cur.u].size();
        for(int i=0; i<len; i++)
        {
            int next = connection[cur.u] [i];
            if( !visited[next] )
            {

                struct node x;
                x.cost = dist[cur.u] [i];
                x. u = next;
                Q.push(x);
            }
        }
    }
    return mx;
}

int main()
{
    int n, c,s,q;
    int tc=1;

    while(scanf("%d %d %d",&c, &s, &q) == 3 && c!=0)
    {
        if(tc>1)
            printf("\n");
        printf("Case #%d\n", tc++);
        int u,v,d,mxDist=0;
        for(int i=0; i<s; i++)
        {
            scanf("%d %d %d", &u, &v, &d);
            connection[u].push_back(v);
            connection[v].push_back(u);
            if(d>mxDist)
                mxDist = d;
            dist[u].push_back(d);
            dist[v].push_back(d);
        }

        while(q--)
        {
            scanf("%d %d", &u, &v);
            int x = bfs(u,v,0);
            if(!visited[v])
                printf("no path\n");
            else
                printf("%d\n", x);
        }
        for(int i=0; i<111; i++)
        {
            connection[i].clear();
            dist[i].clear();
        }
    }
    return 0;
}
