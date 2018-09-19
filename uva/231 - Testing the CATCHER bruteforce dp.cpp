#include<bits/stdc++.h>
using namespace std;

int ara[32867], len, dp[32867], dpVisit[32867], dpCnt=1;

int rec(int pos, int prev)
{
    if(pos == len)
        return 0;
    int& vis = dpVisit [pos];
    int& ret = dp[pos];

    if(vis == dpCnt)
    {

        return max(ret, rec(pos+1, prev));

    }
    ret =0;

    if(ara[pos] <= prev)
    {

        ret = rec(pos+1, ara[pos])+1;

        vis = dpCnt;
    }
    int y = rec(pos+1, prev);


    return  max(ret,y);
}

int main()
{
//    freopen("myIn.txt", "r", stdin);
//    freopen("myOut.txt", "w", stdout);
    int t=1;
    while(1)
    {
        len=0;
        while(scanf("%d", &ara[len])==1 && ara[len]!= -1) len++;

        if(!len)
            return 0;
        if(t>1)
            printf("\n");
//        memset(dp, -1, sizeof dp);
        printf("Test #%d:\n  maximum possible interceptions: %d\n",t++, rec(0, 32866));

        dpCnt++;
    }


}

