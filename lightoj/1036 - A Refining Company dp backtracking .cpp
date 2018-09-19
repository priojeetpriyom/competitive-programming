#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 505

int dp[MX][MX];
int tc, vis[MX][MX];
int ura[MX] [MX], radi[MX] [MX];
int n, m;


int rec(int r, int c)
{
    //    printf("i %d j %d\n", i, j);
    if(!r || !c) return 0;

//    int rad = (path[r-1][c] !=URANIUM), ur= (path[r][c-1] != RADIUM);
    int &ret = dp[r][c];
    int  &v = vis[r][c];
    if(v==tc) return ret;

    ret=0;
    v= tc;
    ret = max(rec(r, c-1)+radi[r][c], rec(r-1, c)+ura[r][c]);

    return ret;


}


int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t;
    scanf("%d", &t);

    for(tc=1; tc<=t; tc++)
    {
        scanf("%d %d", &n, &m);

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                scanf("%d", &ura[i][j]);
                ura[i][j]+=ura[i] [j-1];
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                scanf("%d", &radi[i][j]);
            }
        }
        for(int j=1; j<=m; j++)
        {
            for(int i=1; i<=n; i++)
            {
                radi[i][j]+=radi[i-1][j];
            }
        }


        printf("Case %d: %d\n",tc, rec(n,m));

    }



    return 0;
}
