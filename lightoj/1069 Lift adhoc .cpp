#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 100100


ll rec(int left, int val) {
    if(val<=0)
        return 0;
    if(!left) {
        return -1e9;
    }

    ll ret=0;
    for(int i=1; i<=6; i++)
       ret += max(0LL, rec(left-1, val-i)+1);


    return ret;

}




int main()
{
//    char c;
    int t;
    scanf("%d", &t);
//    memset(dp, -1, sizeof dp);

    for(int tc=1; tc<=t; tc++)
    {
       int me, lift;
       scanf("%d %d", &me, &lift);
       printf("Case %d: ", tc);

       if(!me) {
            printf("0\n");
       } else {
            printf("%d\n", ( abs(me-lift) + me)*4 + 19);
       }


    }



    return 0;
}

