#include<bits/stdc++.h>
using namespace std;

#define Max 1010
struct edge
{
    int u,v,cost;
};
bool compmax(edge A,edge B)
{
    return A.cost>B.cost;
}
edge E[100100];

struct someType {

int first, second;
//    someType(int f, int s)
//    {
//        first = f;
//        second = s;
//    }
} store[Max] [Max];


int parent[Max];

int lenss[1010];
int vis[Max];
int Find(int x)
{
    if(parent[x]==x)return x;
    return parent[x]=Find(parent[x]);
}
void makeparent(int n)
{
    for(int i=0; i<=n; i++)parent[i]=i;
}

int mx=1;
int dp[Max] [Max];

void somesType(int iii,int jjj, int len, int cost) {

    store[iii][len].first = jjj;
    store[iii][len].second = cost;

}


void maxKruskal(int nodes)
{
    sort(E,E+mx,compmax);
//    reverse(E.begin(),E.end());
    int sz= mx;
//    int ans=0,cnt=0;
    makeparent(nodes);
    for(int i=0; i<sz; i++)
    {
        int u= Find(E[i].u), v= Find(E[i].v);

//            cout<<" nodes u, v "<<E[i].u<<" "<<E[i].v<<endl;
        if(u!=v)
        {
            vis[u] = vis[v]=1;
//            cout<<"  u , v = "<<u<<" "<<v<<endl;
            //cnt++;
            parent[u]= v;
//            ans+= E[i].cost;
            int &len1 = lenss[E[i].u];
            somesType(E[i].u,E[i].v, len1, E[i].cost );
            len1++;
            int &len2 = lenss[E[i].v ];
            somesType(E[i].v,E[i].u, len2, E[i].cost );
            len2++;
            //  if(cnt==nodes)break;
//            cout<<"managed  =  "<<E[i].v<<" "<<E[i].u<<endl;
        }
    }
//    return ans;
}
bool ok  = 1;
bool dfs(int a,int x, int b,int y, int par)
{
//    cout<<"path   "<<a<<"  "<<x<<endl;

    if(a == b) {
        ok = true;
        return true;
    }
    if(dp[a][b]!= -1) {
        ok = ok | dp[a][b];
        return dp[a][b];
    }
    dp[a][b] = 0;

    int len = lenss[a];

    for(int i=0; i<len; i++) {
        int& to = store[a][i].first;
        if(to != par && store[a][i].second>=x) {
            dp[a][b] = dp[a][b] | dfs(to, x, b, min(y, store[a][i].second), a);
        }
    }

    return dp[a][b];
}

int main()
{
    memset(dp, -1, sizeof dp);
//#define FastRead        ios_base::sync_with_stdio(0);cin.tie(0)
    int a,b,nodes;
//    int tm,cs=1;
//    cin>>t;
//    while(t--)

//        E.clear();
        scanf("%d", &nodes);
//        makeparent(nodes);
//        edge init;
//    int aa,bb,cc;

//    int mx=1;
        for(int i=0; i<nodes; i++)
        {

            // if(a+b+c==0)break;
            //  init = { a,b,c};
//            cin>>init.u>>init.v>>init.cost;
            edge & init = E[i];
            scanf("%d %d %d", &init.u, &init.v, &init.cost);
            mx = max(mx, max(init.u, init.v));
//            E[i] = init;
        }
        swap(mx, nodes);
        for(int i=1; i<=nodes; i++) {
            if(!vis[i]) {
                maxKruskal(i);
                vis[i]=1;
            }

        }
//        for(int x=1; x<=6; x++)
//        {
//
////            for(int j=0; j<store[x].size() ; j++)
////            { cout<<x<<"  I ";
////                cout<<" check "<< store[x][j].first<<" "<<store[x][j].second<<endl;
////            }
//        }

        int q;
//           cin>>q;
        scanf("%d", &q);
        int x,y;


        while(q--)
        {
//            cin>>a>>x>>b>>y;
            scanf("%d %d %d %d", &a, &x, &b, &y);
            ok = 0;
            dfs(a, x,b,y,-1);

            if(ok) printf("Yes\n");
            else printf("No\n");



        }



    return 0;

    //cout<<Kruskal(nodes)<<endl;
}
