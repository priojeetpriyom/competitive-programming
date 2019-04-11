#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll dp[202] [12] [22], visited[202] [12] [22], v=1;
int n, m, ara[202],d;

ll rec(int pos, int taken, int mod) {

    if(taken==m && mod==0) return 1;
    if(pos == n || taken==m || m-taken> n-pos) return 0;

    ll &ret = dp[pos] [taken] [mod];
    ll &vis = visited[pos] [taken] [mod];
    if(vis == v) return ret;
    ret=0;
    vis = v;

    ret = rec(pos+1, taken+1,  (mod+ (ara[pos]%d )+d )%d ) + rec(pos+1, taken, mod);
    return ret;

}



int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);


    int tc=1,q;

    while(scanf("%d %d", &n, &q)==2 && n!=0) {

     for(int i=0; i<n; i++)
        scanf("%d", &ara[i]);

        printf("SET %d:\n", tc++);

        for(int qu=1; qu<=q; qu++) {
            v++;
            scanf("%d %d", &d, &m);
            printf("QUERY %d: %lld\n", qu, rec(0, 0, 0));
        }

    }



    return 0;
}
