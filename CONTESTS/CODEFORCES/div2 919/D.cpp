#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 300100

vector<int> conn[MX];
char str[MX];
int xx=2, vis[MX];

int mark[MX] [30];

int inf=0;

//int len;
int mx=1;
void dfs(int u)
{

    int len= conn[u].size();
    vis[u]=xx;
    for(int i=0; i<len; i++)
    {
        int &v = conn[u][i];

        if(vis[v] ==xx)
        {
//            printf("INF FOR U %d V %d VISTED BEFORE\n", u,v);
            inf=1;
            return;
        }
        if(!vis[v])
        {


            dfs(v);
        }
//        else printf("U %d V %d VISTED BEFORE\n", u,v);

//        printf("U %d V %d conn_s %d i %d\n", u,v, conn[u].size(), i);
        for(int i=0; i<26; i++)
        {
            mark[u][i] = max(mark[u][i], mark[v][i]);
            mx = max(mx, mark[u][i]);
//            printf("%d ", mark[u][i]);
        }
//        printf("\n");
    }

    mark[u][str[u]]++;
    mx = max(mx, mark[u][str[u] ]);
    vis[u]=1;


}



int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;

    scanf("%d %d", &n, &m);
    scanf("\n%s", str+1);
//    printf("%s\n", str+1);
    int u,v;
    for(int i=1; i<=n; i++)
        str[i] -='a';

//    for(int i=1; i<=n; i++)
//        printf("%d ",str[i]);
//    printf("\n");

    for(int i=1; i<=m; i++)
    {
        scanf("%d %d", &u, &v);
        if(u==v)
            inf=1;
        conn[u].push_back(v);
    }

//    for(int i=1; i<=n; i++) {
//            printf("%d=>", i);
//        for(int j=0; j<conn[i].size(); j++) {
//            printf("%d,", conn[i][j]);
//        }
//        printf("\n");
//    }
    if(!inf)
    for(int i=1; i<=n; i++)
    {
        if(inf)
            break;
        if(!vis[i])
        {
            xx++;
//            printf("called for %d\n", i);
            dfs(i);
        }
    }

//    for(int i=0; i<26; i++)
//        printf("%d ", mark[1][i]);

    if(inf)
        printf("-1\n");
    else
        printf("%d\n", mx);



    return 0;
}


