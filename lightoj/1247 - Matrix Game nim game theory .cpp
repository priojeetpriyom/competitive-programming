#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 55

//int ara[105];

int main()
{

    int t;
    scanf("%d", &t);
//    memset(dp, -1, sizeof dp);

    int n, m;


    for(int tc=1; tc<=t; tc++)
    {
        ll ans=0;

        scanf("%d %d", &n, &m);
//        scanf("%d", &now);
//        k+=k;
        ll sum, x;
        for(int i=0; i<n; i++) {
            sum=0;
            for(int j=0; j<m; j++)
            {
                scanf("%lld",&x);
                sum+=x;
            }
            ans^=sum;

        }

        printf("Case %d: ",tc);
        if(ans >0) {
            printf("Alice\n");
        } else
            printf("Bob\n");


    }



    return 0;
}
