#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int r,m, dp[7100][3], vis[7100] [3];
int R[7100],  M[7100];
int n;
int choice;
int rec(int pos, int player)
{
    printf("pos %d player %d\n", pos, player);
    pos = pos %n;
    if(!pos) pos=n;
    if(pos==1) {
//        printf("base case\n");
        return 2;
    }

    if(vis[pos] [player]) return (1);
    int &ret = dp[pos] [player];
    if(ret!= -1) {
        printf("returned %d\n",ret);
//        return ret;
    }
    vis[pos] [player] =1;
//    dp[player] [pos];
    int ans = -1;
    if(player == 1)
    {

        for(int i=0; i<r; i++)
        {
            ret = max(rec(pos+ R[i], 2), ret);



        }
    }
    else
    {
        for(int i=0; i<m; i++)
        {
            ret = max(rec(pos+ M[i], 1), ret);
        }
    }
    vis[pos][player]  =0;
//    printf("pos %d player %d ans %d\n", pos, player, ret);
    if(ret==2) return 0;
    if(ret==0) return 2;
//     if(ret==1 )return 1;

    return ret;
}


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    memset(dp, -1, sizeof dp);
    cin>>n;
    dp[1][1] = dp[1][2] = 0;
    scanf("%d", &r);
    for(int i=0; i<r; i++) scanf("%d", &R[i]);
    scanf("%d", &m);
    for(int i=0; i<m; i++) scanf("%d", &M[i]);

    for(int i=2; i<=n; i++)
    {
        printf("CALL for 1\n");
        rec(i, 1);
        printf("CALL for 2\n");
        rec(i, 2);
    }
    for(int i=2; i<=n; i++)
    {
        if(dp[i] [1] ==2)
            printf("Win ");
        else if(dp[i] [1] == 0)
            printf("Lose ");
        else
            printf("Loop ");
//            printf("Loop%d ", dp[i][1]);
    }
    printf("\n");
    for(int i=2; i<=n; i++)
    {
        if(dp[i] [2] ==2)
            printf("Win ");
        else if(dp[i] [2] == 0)
            printf("Lose ");
        else
            printf("Loop ");
//            printf("Loop%d ", dp[i][2]);
    }

    printf("\n\n\n"); rec(7 ,2);

    return 0;
}


