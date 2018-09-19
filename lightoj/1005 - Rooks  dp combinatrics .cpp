#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

ll dp[33][33];


int mask[33];
int row;

ll rec(int n, int k) {
//    printf("n %d k %d\n", n, k);
    if(k>n) return 0;
    if(!k) return 1;

    ll &ret = dp[n][k];
    if(~ret) return ret;
    ret=0;

    for(int i=1; i<=row; i++) {
        if(!mask[i]) {
            mask[i]=1;
            ret+= rec(n-1, k-1);
            mask[i]=0;
        }
    }

    ret+= rec(n-1, k);

    return ret;



}


int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);


    int n, k;

    int t;
    scanf("%d", &t);

    for(int tc=1; tc<=t; tc++) {
        memset(dp, -1, sizeof dp);
        scanf("%d %d", &row, &k);
        printf("Case %d: ", tc);

        printf("%lld\n", rec(row, k));



    }



    return 0;
}

