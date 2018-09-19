#include <bits/stdc++.h>
using namespace std;

long long a, b, c, d, e, f;
long long ara[10011];
long long fn( int n )
{
    if(n<0) return 0;
    if(n<6)
        return ara[n];
    if( ara[n] != INT_MIN ) return ara[n];
    return ara[n] = ( fn(n-1)% 10000007 + fn(n-2)% 10000007 + fn(n-3)% 10000007 + fn(n-4)% 10000007 + fn(n-5)% 10000007 + fn(n-6)% 10000007 )% 10000007;
}
int main()
{
//    freopen("myOutput.txt","w",stdout);
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- )
    {
        scanf("%lld %lld %lld %lld %lld %lld %d", &a, &b, &c, &d, &e, &f, &n);
        for(int i=0; i<=n;i++)
            ara[i]= INT_MIN;
        ara[0] = a;
        ara[1] = b;
        ara[2] = c;
        ara[3] = d;
        ara[4] = e;
        ara[5] = f;
//        if(n<6) {
//
//        }
//        else {
            fn(n);
        printf("Case %d: %lld\n", ++caseno, ara[n]%10000007);
//        }

    }
    return 0;
}
