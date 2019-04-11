#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("myOutput.txt","w",stdout);
    long long n,a,b,c;
    scanf("%I64d",&n);
    a=n;
    n = n*n;
    if(n == 1)
        printf("-1\n");
    else if(n%2==0) {
        n/=2;
        b= n/2-1;
        c= n/2+1;
        if(a+b>c && b+c>a && a+c>b)
            printf("%I64d %I64d\n",b,c );
        else
            printf("-1\n");
    } else
        {
            b= n/2;
            c= n/2+1;
            if(a+b>c && b+c>a && a+c>b)
                printf("%I64d %I64d\n",b,c);
            else
                printf("-1\n");
        }

    return 0;
}
