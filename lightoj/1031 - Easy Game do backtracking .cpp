#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 103

int dp[MX][MX] [3];
int tc, vis[MX][MX] [3];
int ara[MX];
int n, m;


int rec(int s, int f, int turn)
{
//        printf("s %d f %d turn %d\n", s, f, turn);
    if(s>f) return 0;


    int &ret = dp[s][f] [turn];
    int  &v = vis[s][f] [turn];
    if(v==tc) return ret;

    ret=1e9;
    v= tc;
    int temp=-1e9, x;
    for(int i=s; i<=f; i++)
    {
        x = rec(i+1,f,turn^1);
        temp = max(temp,x + (ara[i]-ara[s-1]) );
        ret = min(ret, x);
    }

    for(int i= f; i>=s; i--)
    {
        x = rec(s,i-1,turn^1);
        temp = max(temp, x + (ara[f]-ara[i-1]) );
        ret = min(ret, x);
    }

    if(turn)
    {
        ret=temp;
    }
    //    printf("r %d c %d ret %d\n", r, c, ret);
    //
    //    for(int i=1; i<=n; i++) {
    //        for(int j=1; j<=m; j++) {
    //            printf("%d ", vis_ura[i][j]);
    //        }
    //        printf("\n");
    //    }

//        printf("s %d f %d turn %d ret %d\n", s, f,turn,  ret);
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
        scanf("%d", &n);

        for(int i=1; i<=n; i++)
        {
            scanf("%d", &ara[i]);
            ara[i]+= ara[i-1];
        }
        int a = rec(1,n, 1);
        printf("Case %d: %d\n",tc, a - (ara[n]-a));

    }



    return 0;
}

