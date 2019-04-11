#include <bits/stdc++.h>
using namespace std;
struct node{
    int connection,cost;
};
vector<node> cost[20001];
int final_cost[20001];
//vector<int> connection[20001][];
struct node currentNode;

bool operator<(const node& a, const node& b)
{
    return a.cost>b.cost;
}

void find_minimum_latency()
{
    priority_queue<node> pq;
    pq.push(currentNode);

    while(pq.size())
    {
        currentNode = pq.top();
        pq.pop();

        for(int i=0; i< cost[currentNode.connection].size(); i++)
        {
            if((currentNode.cost+ cost[currentNode.connection][i].cost) < final_cost[cost[currentNode.connection] [i].connection])
            {
                node newNode;
                newNode.cost = currentNode.cost+ cost[currentNode.connection][i].cost;
                newNode.connection = cost[currentNode.connection][i].connection;
                pq.push(newNode);

                final_cost[cost[currentNode.connection] [i].connection] = newNode.cost;
            }
        }
    }
}

int main()
{

//    freopen("myInput.txt","r", stdin);
//    freopen("myOutput.txt","w",stdout);

    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++)
    {
        int n,m,s,t;

        scanf("%d %d %d %d", &n, &m, &s, &t);
        int j;
        for(j=0; j<m; j++)
        {
            final_cost[j]=INT_MAX;
            int u,v,x;
            scanf("%d %d %d", &u, &v, &x);
            currentNode.cost=x;

            currentNode.connection=u;
            cost[v].push_back(currentNode);

            currentNode.connection=v;
            cost[u].push_back(currentNode);

        }for( ; j<n; j++)
            final_cost[j]= INT_MAX;

        currentNode.cost=0;
        currentNode.connection = s;

        find_minimum_latency();
        if(final_cost[t] == INT_MAX)
            printf("Case #%d: unreachable\n",i,final_cost[t]);
        else
            printf("Case #%d: %d\n",i,final_cost[t]);

        for(int j=0; j<n; j++)
            cost[j].clear();

    }


    return 0;
}
