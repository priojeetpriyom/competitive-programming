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
    long long k, a, b;
    scanf("%I64d %I64d %I64d",&k, &a, &b);
    if(a<1)
    {
        if(b<0)
            printf("%I64d\n",logCalc(abs(a), k) - logCalc(abs(b)-1, k));
        else
            printf("%I64d\n",logCalc(abs(b), k) + logCalc(abs(a), k)+1);
    }
    else
        printf("%I64d\n",logCalc(abs(b), k) - logCalc(abs(a-1), k));

    return 0;
}


