#include <iostream>
#include <cstdio>
using namespace std;
int main ()
{
    long long int n,i,num;
    while(scanf("%lld",&num) == 1) {
        n=0;
        for(i=1;i<=num;i=i+2) {
            n=i+n;
    }
        printf("%lld\n",n+n+n+n+n+n-9);
    }
    return 0;
}
