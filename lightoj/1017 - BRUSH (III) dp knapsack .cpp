#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 105

ll dp[MX][MX], ara[MX];
int n, k ,w;


int get_pos(int pos) {
    int prev = pos;
    do{
        pos++;
    } while(pos<n && ara[pos]<= ara[prev]+w);

    return pos;
}


ll rec(int pos, int left)
{
    if(!left) return 0;

    if(left > n-pos) return n-pos;

    ll &ret = dp[pos] [left];
    if(~ret) return ret;
    ret=0;

    int newPos = get_pos(pos);
    ret = max(rec(newPos, left-1)+newPos-pos, rec(pos+1, left));


    return ret;


}


int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t;
    scanf("%d", &t);

    for(int tc=1; tc<=t; tc++)
    {
        memset(dp, -1, sizeof dp);

        scanf("%d %d %d", &n,&w, &k);

        for(int i=0; i<n; i++) {
            scanf("%lld %lld",&ara[103], &ara[i]);
        }
        ara[n] = 1e10;




        printf("Case %d: %lld\n",tc, rec(0,min(n,k)));

    }



    return 0;
}
