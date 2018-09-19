#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int coins[] = {50,25,10,5,1}, dp[6] [7589];
    int n;

int rec(int pos, int left) {
    if(left ==0 )
        return 1;
    if(left <0 || pos == 5)
        return 0;

    int &ret = dp[pos] [left];

    if(ret != -1)
        return ret;

    return ret= rec(pos, left-coins[pos]) + rec(pos+1, left);
}

int main()
{
//    freopen("myIn.txt", "r", stdin);
//    freopen("myOut.txt", "w", stdout);

        memset(dp, -1, sizeof dp);
    dp[0][0]=1;
    for(int i=1; i<=7489; i++)
    {
        rec(0, i);
    }

    while(scanf("%d", &n)==1) {
        printf("%d\n", dp[0][n]);
    }


    return 0;


}



