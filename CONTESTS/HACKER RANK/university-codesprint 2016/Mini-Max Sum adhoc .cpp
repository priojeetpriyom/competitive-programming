#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);

    long long ara[10];
    long long n, len=0, sum=0;
    while(scanf("%lld", &n) ==1) {
          ara[len++] = n;
          sum+=n;
        if(len == 5) {
            sort(ara, ara+5);
            printf("%lld %lld\n", sum-ara[4], sum-ara[0]);
            sum=0;
            len=0;
        }
          }

    return 0;
}
