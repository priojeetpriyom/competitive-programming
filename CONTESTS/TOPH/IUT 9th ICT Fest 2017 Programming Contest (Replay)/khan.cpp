#include <bits/stdc++.h>
#define pb push_back

using namespace std;

vector < int > ve[510];
  int arr[1010][1010];
    int vis[1010];
    int weight[1010];
int main()
{
    int i,j,k,m,w,p,q, home, g,n,t, cs = 0,u,v;

    queue < int>qu;
    scanf("%d", &t);

    while(t--)
    {
        memset(arr,0, sizeof(arr));
        scanf("%d", &n);
        scanf("%d", &m);
        while(m--)
        {
            scanf("%d", &u);
            scanf("%d", &v);
            scanf("%d", &w);
            if(arr[u][v] == 0 )
            {
                arr[u][v] = w;
                arr[v][u] = w;
                ve[u].pb(v);
                ve[v].pb(u);
            }
            else
            {
                arr[u][v] = max(arr[u][v], w);
                arr[v][u] = max(arr[v][u], w);
            }
        }

  //      scanf("%d", &home);
  //      printf("Case %d:\n", ++cs);

        i = 1;
        memset(vis,0, sizeof(vis));
        for(j=0; j<=1010; j++) weight[j] = -1;
        qu.push(i);
        vis[i] = 1;
        weight[i] = 0;


        while( !qu.empty())
        {
            q = qu.front();
            qu.pop();
            for(j=0; j<ve[q].size(); j++)
            {
                // cout << "Ok" <<endl;
                if(ve[q][j] == home)
                    weight[ve[q][j]] = max(weight[home],max(weight[q], arr[q][ve[q][j]]));

                else if(vis[ve[q][j]] == 0)
                {
                    vis[ve[q][j]] = 1;
                    qu.push(ve[q][j]);
                    weight[ve[q][j]] = max(weight[q], arr[q][ve[q][j]]);
                }
                else
                {
                    if(weight[ve[q][j]] >max(weight[q], arr[q][ve[q][j]]))
                    {
                        qu.push(ve[q][j]);
                        weight[ve[q][j]] = max(weight[q], arr[q][ve[q][j]]);
                    }
                }
            }
        }




        for(i=1; i<=n; i++)
        {
            if(home == i)
            {
                printf("0\n");
            }
            else if(weight[i] != 222222222)
            {
                printf("%d\n", weight[i]);
            }
            else
                printf("Impossible\n");
        }
        for(i=0; i<n+5; i++)
        {
            ve[i].clear();
        }
    }
}

