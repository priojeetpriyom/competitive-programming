#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int dp[1<<16+5];
bool CHECK(int mask, int pos) {
    return mask & (1<<pos);
}
int SET(int mask, int pos) {
    return mask | (1<<pos);
}

int n;
int ara[20][20];
int rec(int pos, int mask) {

    if(pos == n)
        return 0;

    int &ret = dp[mask];

    if(~ret) return ret;
    ret=0;

    for(int i=0; i<n; i++) {
        if(!CHECK(mask, i)) {
            ret = max(ret, rec(pos+1, SET(mask, i))+ara[pos][i]);
        }
    }

    return ret;


}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t;
    scanf("%d", &t);

    for(int tc=1; tc<=t; tc++) {
        memset(dp, -1, sizeof dp);
        scanf("%d", &n);

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                scanf("%d", &ara[i][j]);
            }
        }

        printf("Case %d: %d\n",tc, rec(0, 0));

    }



    return 0;
}
