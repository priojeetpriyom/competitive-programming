///this is a two state dp problem with one state being remainingMoves and other is the current city.


#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
//#define MX 505

int dp[1010][110];
int tc, vis[1010][110];
int endd[110];
int n, m;
int profit[110] [110];

int rec(int mov, int cur)
{
    //    printf("i %d j %d\n", i, j);
    if(!mov)
    {
        return (endd[cur]==1)? 0: -1e9;
    }

//    int rad = (path[r-1][c] !=URANIUM), ur= (path[r][c-1] != RADIUM);
    int &ret = dp[mov][cur];
    int  &v = vis[mov][cur];
    if(v==tc) return ret;

    ret=0;
    v= tc;
    for(int i=1; i<=n; i++)
    {
        if(cur!=i)
            ret = max(ret, rec(mov-1, i)+profit[cur][i]);
    }

    return ret;


}


int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

//    int t;
//    scanf("%d", &t);
    int x, s, e, mov;
    tc=1;
    while(scanf("%d %d %d %d", &n, &s, &e, &mov) && n!=0)
    {
        tc++;
        memset(endd, 0, sizeof endd);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                scanf("%d", &profit[i][j]);
            }
        }
        while(e--)
        {
            scanf("%d", &x);
            endd[x]=1;
        }
//        printf("aise n %d\n", n);
        printf("%d\n", rec(mov, s));
    }



    return 0;
}
