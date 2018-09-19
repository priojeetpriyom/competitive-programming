#include <bits/stdc++.h>
using namespace std;

struct node
{

    int u, v;
    int cost;
};

bool cmp(node a, node b)
{
    return a.cost>= b.cost;

}
priority_queue<node, vector<node>, decltype(&cmp)> pq(&cmp);
vector<pair<int, int> > conn[1000100];


    int vis[1000100];

int mst(int n)
{
    while(!pq.empty()) pq.pop();

    node a;
    int len=conn[1].size();
    for(int i=0; i<len; i++)
    {
        a.u =1;
        a.v = conn[1][i].first;
        a.cost = conn[1][i].second;
        pq.push(a);
    }
    memset(vis, 0,sizeof vis);
    vis[1]=1;
    int ans=0;
    int cnt=1;
    while(cnt<n)
    {

        a = pq.top();
        pq.pop();
        if(vis[a.u] && vis[a.v]) continue;

        ans+= a.cost;
        cnt++;
        if(vis[a.u]) swap(a.u, a.v);
        vis[a.u]=1;

        len = conn[a.u].size();
        node b;
        b.u = a.u;
        for(int i=0; i<len; i++)
        {
//            printf("u %d v %d cost %d vis %d\n",a.u, conn[a.u][i].first, conn[a.u][i].second, vis[conn[a.u] [i].first ] );
            if(!vis[ conn[a.u] [i].first ])
            {
                b.v = conn[a.u][i].first;
                b.cost = conn[a.u] [ i ].second;
                pq.push(b);
            }

        }
//        printf("cnt %d a_u %d a_v %d ans %d\n",cnt, a.u,a.v, ans );
//        printf("pq top u %d v %d cost %d\n", pq.top().u, pq.top().v, pq.top().cost );


    }

    return ans;

}


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n=-1;
    int u=-1, v, cost;

    while(cin>>n)
    {
        int pre_ans=0;
        if(u!= -1) cout<<endl;
        for(int i=1; i<n; i++)
        {
            cin>>u>>v>>cost;
            pre_ans+= cost;
            conn[i].clear();
        }
        conn[n].clear();


        int k,m;
        cin>>k;
        node a;
        for(int i=0; i<k; i++)
        {
            cin>>u>>v>>cost;
//        a.u=u;
//        a.v=v;
//        a.cost  = cost;
            conn[u].push_back(make_pair(v, cost));
            conn[v].push_back(make_pair(u, cost));
        }
        cin>>m;
        for(int i=0; i<m; i++)
        {
            cin>>u>>v>>cost;
//        a.u=u;
//        a.v=v;
//        a.cost  = cost;
            conn[u].push_back(make_pair(v, cost));
            conn[v].push_back(make_pair(u, cost));
        }

        cout<<pre_ans<<endl;
        cout<< mst(n)<<endl;;

    }

    return 0;
}


