#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 100100

int ara [MX] [6];


int main()
{

    int t;
    scanf("%d", &t);
//    memset(dp, -1, sizeof dp);

    for(int tc=1; tc<=t; tc++)
    {
        int n, q;
        scanf("%d", &n);

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=4; j++) {
                scanf("%d", &ara[i][j]);
            }
        }

        scanf("%d", &q);

        while(q--) {
            ll t, mn = 1e18;
            scanf("%lld", &t);

            for(int i=1; i<=n; i++) {
                ll temp =0, pw=1;
                for(int j=1; j<=4; j++) {
                    temp += (pw*ara[i][j]);
                    pw*=t;
                }
                mn = min(mn, temp);
            }

            printf("%lld\n", mn);

        }


    }



    return 0;
}
