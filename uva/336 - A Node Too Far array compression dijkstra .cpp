#include <bits/stdc++.h>
using namespace std;
vector<int> connection[40];
int cost[40];
int ttl;
struct node
{
    int pos, cost;
};
int calc(int start)
{
//    printf("start index %d\n", start);
    queue<struct node> Q;
    cost[start] =0;
    struct node curr;
    curr.cost=0;
    curr.pos=start;
    Q.push(curr);

    while(!Q.empty())
    {
//        printf("aaaaa")

        curr = Q.front();
        Q.pop();
        if(curr.cost == ttl) continue;
        int len = connection[curr.pos].size();
        for(int i=0; i<len; i++)
        {
            if(curr.cost+1 < cost[connection[curr.pos] [i] ])
            {
                cost[connection[curr.pos] [i] ] = curr.cost+1;

                struct node next;
                next.pos = connection[curr.pos] [i];
                next.cost = curr.cost+1;
                Q.push(next);
            }
//            printf("cccc\n");
        }
//        printf("dfd\n");
    }
    int x=0;
    for(int i=1; i<40; i++)
        if(cost[i]!= INT_MAX)
        {
            x++;
        }
    return x;
}


int main()
{

    int n, t=1;
    while(scanf("%d", &n)==1 && n!=0)
    {
        map<int, int>  mp;
        int ass =1;
        for(int i=0; i<n; i++)
        {
            int x,y;
            scanf("%d %d", &x, &y);

            if(!mp[x])
                mp[x] =ass++;
            if(!mp[y])
                mp[y] = ass++;
            x = mp[x];
            y= mp[y];
            connection[x].push_back(y);
            connection[y].push_back(x);
        }
//        printf("ass %d\n",ass);

//        int visited[40];
//        memset(visited, 0, sizeof(visited));
        int start;
        while(scanf("%d %d", &start, &ttl)==2 && !(ttl==0 && start==0))
        {
//            printf("start has %d connections", connection[mp[start] ].size());
            for(int i=0; i<40; i++)
                cost[i] = INT_MAX;
            int x = calc(mp[start])+1;
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", t++, ass-x, start, ttl);
        }
        for(int i=0; i<40; i++)
            connection[i].clear();
    }
    return 0;
}
