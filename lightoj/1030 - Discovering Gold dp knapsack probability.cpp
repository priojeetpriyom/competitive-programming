#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 105

int n;
double dp[MX], ara[MX];
int vis[MX], tc;


double rec(int pos) {
//    printf("pos %d\n", pos);
    if(pos == n) {
        return ara[pos];
    }
    double &ret = dp[pos];
    if( vis[pos] == tc) return ret;
    vis[pos] = tc;
    ret=0;
    int i;
    for(i=1; i<=6 && i+pos <=n; i++) {
        ret+= ara[pos]+rec(i+pos);
    }
//    printf("1 pos %d ret %lf i %d\n", pos, ret, i-1);
////    if(first) ret+= ara[1];
//    printf("2 pos %d ret %lf i %d\n", pos, ret, i-1);
    ret/= (i-1);
//    printf("3 pos %d ret %lf i %d\n", pos, ret, i-1);

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
        scanf("%d", &n);
        for(int i=1; i<=n; i++)
            scanf("%lf", &ara[i]);

        printf("Case %d: %lf\n",tc,  rec(1 ));
    }



    return 0;
}
