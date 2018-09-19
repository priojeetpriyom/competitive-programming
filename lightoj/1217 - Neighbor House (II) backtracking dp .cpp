#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int ara[1111];

int n;
int dp[1111] [2][2];
int visited[1111] [2][2], tc;

int rec(int pos, int prev, int first) {

    if(pos == n+1) return 0;

    int &ret = dp[pos] [prev] [first];
    int &vis = visited[pos] [prev] [first];

    if(vis == tc) return ret;
    vis = tc;
    ret=0;
    if(!prev) {
        if(pos==n && first);
        else
            ret = rec(pos+1, 1, first || (pos==1) ) + ara[pos];
    }

    return ret = max(ret, rec(pos+1, 0, first));


}



int main()
{


//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    int t;

    scanf("%d", &t);

    for( tc=1; tc<=t; tc++) {
        scanf("%d", &n);

        for(int i=1; i<=n; i++) {
            scanf("%d", &ara[i]);
        }

        printf("Case %d: %d\n",tc, rec(1, 0,0) );
    }


    return 0;
}





