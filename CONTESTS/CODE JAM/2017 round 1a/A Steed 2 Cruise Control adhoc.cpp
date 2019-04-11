#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



int main()
{


//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int t;
    ll n, k, d,s;
    scanf("%d", &t);

    for(int tc=1; tc<=t; tc++) {
        scanf("%lld %lld", &d, &n);
        double mx_time = -1;
        for(int i=0; i<n; i++) {
            scanf("%lld %lld", &k, &s);
            mx_time = max(mx_time, ((double)d-k)/s);
        }

        printf("Case #%d: %lf\n",tc,  d/mx_time);
    }

    return 0;
}




