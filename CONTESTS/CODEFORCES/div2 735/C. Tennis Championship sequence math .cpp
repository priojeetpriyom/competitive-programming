#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("myOut.txt", "w", stdout);

    long long n;
    scanf("%I64d", &n);
//    n-=2;
//
//    n*=2;
//
//    n = 1+ n*4;
//    n = sqrt(n);
//    n = n-1;
//    n = n /  2;
//    n++;
    long long sum=0, f1=1, f2=1;
    for(long long i=1; ; i++) {
        sum = f1+f2;
        f1=f2;
        f2=sum;
        if(sum>=n) {
            if(sum > n)
                i--;
            printf("%I64d\n", i);
            break;
        }
    }
//    printf("%I64d\n", n);

    return 0;
}

