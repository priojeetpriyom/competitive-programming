#include <bits/stdc++.h>
using namespace std;

long long logCalc(long long n, long long k)
{
    return n/k;
}
int main()
{
//    freopen("myOutput.txt","w",stdout);
    //freopen("myInput.txt",") ;;;we
    int t;
    scanf("%d", &t);
    while(t--)
    {
        long long n,sum;
        scanf("%I64d", &n);
        sum=0;
        for(long long i=1; i<=n; i= i+i)
            sum+=i;
        sum+=sum;
        n= n*(n+1);
        n/=2;
        printf("%I64d\n",n-sum);
    }
    return 0;
}


