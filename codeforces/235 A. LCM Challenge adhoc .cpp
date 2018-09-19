#include <bits/stdc++.h>
using namespace std;
long long GCD(long long a, long long b)
{
    return (a%b==0)? b : GCD(b,a%b);
}
long long LCM(long long a, long long b)
{
    return ( (a*b)/GCD(a,b));
}
int main()
{

//    freopen("myInput.txt","r", stdin);
//    freopen("myOutput.txt","w",stdout);
//    printf("gcd %d", GCD(25,125));
    long long n;
    scanf("%I64d",&n);
    long long lcm = n*(n-1);
    if(lcm<=0)
        lcm=1;
    long long  mx = lcm;
    int root = sqrt(n);
    int num = n-2;
    while(num>=1)
    {
        long long x= (LCM(num,lcm));
        if(x>mx)
            mx=x;
        num--;
    }
    lcm = (n-1)*(n-2);
    if(lcm<=0)
        lcm=1;
    num = n-2;
    while(num>=1)
    {
        long long x= (LCM(num,lcm));
        if(x>mx)
            mx=x;
        num--;
    }
    printf("%I64d\n", mx);
    return 0;
}
