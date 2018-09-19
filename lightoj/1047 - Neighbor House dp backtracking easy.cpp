#include <bits/stdc++.h>

using namespace std;

int n, dp[22][4], ara[22][4];

int rec(int pos, int prev) {
    if(pos == n) {
        return 0;
    }

    int &ret = dp[pos] [prev];
    if(ret!= -1)
        return ret;
    ret = INT_MAX;
    for(int i=1; i<=3; i++) {
        if(prev != i) {
            ret = min(ret, rec(pos+1, i)+ara[pos][i]);
        }
    }
    return ret;
}


int main()
{
//   freopen("out.txt", "w", stdout);

    int t;
    cin>>t;

    for(int tc=1; tc<=t; tc++) {
        scanf("%d", &n);
        memset(dp, -1, sizeof dp);

        for(int i=0; i<n; i++) {
            for(int j=1; j<=3; j++)
                scanf("%d", &ara[i][j]);
        }

        printf("Case %d: %d\n",tc, rec(0, 0));

    }

    return 0;
}

