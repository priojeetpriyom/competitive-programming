#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 66

ll  dp[MX] [MX], vis[MX] [MX], tc;
char str[MX];


ll rec(int i, int j)
{
//    printf("i %d j %d\n", i, j);
    if(i>j) return 1;

    ll &ret = dp[i] [j];
    if( vis[i][j] == tc) return ret;
    ret = 0;
    vis[i][j] = tc;

    ret+=rec(i+1, j);
    ret+=rec(i, j-1);

    if(str[i] == str[j])
    {
        ret+= rec(i+1, j-1);
    }
    ret-= rec(i+1, j-1);

    return ret;


}


int main()
{
//    freopen("myOut.txt", "w", stdout);
//    ios_base::sync_with_stdio(0);  cin.tie(0);

    int t;
    scanf("%d", &t);

    for( tc=1; tc<=t; tc++)
    {
        int sum=0;
        int n, x, neg=0;
        scanf("%d", &n);

        for(int i=0; i<n; i++) {
            scanf("%d", &x);
            sum+= abs(x);
            if(x<0) neg++;
        }

        printf("Case %lld: ",tc);
        if(n-neg) {
            int denom = n- neg;
            int gcd = __gcd(denom, sum);
            if(gcd>1) {
                denom/=gcd;
                sum/=gcd;
            }
            printf("%d/%d\n", sum, denom);
        }else
            printf("inf\n");
    }



    return 0;
}

