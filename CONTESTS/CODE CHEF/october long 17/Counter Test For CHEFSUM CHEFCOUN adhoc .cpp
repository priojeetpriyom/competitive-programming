#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 105

ll lim_int = 4294967295LL;


int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout<<lim_int - ( (1LL)<<32)+1;
    int t;
    scanf("%d", &t);

    for(int tc=1; tc<=t; tc++)
    {
        ll n;
        scanf("%lld", &n);
        ll div = (lim_int/(n));

//        if(lim_int% (n-1)==0) {
//           div--;
//        }


        for(int i=2; i<n; i++)
            printf("%lld ", (div));

        ll last = lim_int - ( (n-2)*div ), err=1;
        if(last-2 > 100000LL) {
            ll rem = last - 100000LL;
            last = 100000LL;
            err = rem/2;
        } else last-=2;

        printf("%lld %d", last ,err);
        printf("\n");

//        printf("Case %d: %d\n",tc, rec(0, strlen(str)-1));

    }



    return 0;
}
