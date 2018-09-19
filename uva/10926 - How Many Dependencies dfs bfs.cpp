#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int connection [111][111], vis[111], n;
int dp[111] [111];
int rec(int pos, int prev)
{
    int &ret= dp[pos] [prev];
//    if(ret!= -1) {
//        printf("pos %d returned %d\n", pos, ret);
//        return ret;
//    }
    ret =0;

    for(int i=1; i<=n; i++)
    {
        if(connection[pos] [i] && !vis[i])
        {
            vis[i]=1;
//            printf("pos %d i %d\n", pos ,i);
            ret  += rec(i, pos)+1;
        }
    }
//    vis[pos]=0;
    return ret;
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int x, y;
    while(scanf("%d", &n)==1 && n!=0)
    {
        memset(connection, 0, sizeof connection);
//        memset(dp, -1, sizeof dp);
        for(int i=1; i<=n; i++)
        {
            scanf("%d", &x);
            for(int j=0; j<x; j++)
            {
                scanf("%d",&y);
                connection[i] [y]=1;
            }
        }

//        for(int i=1; i<=n; i++) {
//            for(int j=1; j<=n; j++) {
//                printf("%d ", connection[i][j]);
//            }
//            printf("\n");
//        }


        int mx = -1, mx_task = 1;
        for(int i=1; i<=n; i++)
        {
            memset(vis, 0, sizeof vis);
//            vis[i]=1;
            x = rec(i, 0);
            if(x>mx)
            {
                mx = x;
                mx_task = i;
            }
//            printf("i %d dp %d\n", i, dp[i][0]);

        }
        printf("%d\n", mx_task);
//        printf("mx %d\n", mx);
////        for(int i=1; i<=n; i++)
//            printf("%d ", rec(2,0));
//            printf("%d ", rec(2,0));
    }



    return 0;
}




