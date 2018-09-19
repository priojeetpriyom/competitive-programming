#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y)
{
    return (x%y==0)? y:gcd(y,x%y);
}
long long lcm(long long x, long long y)
{
    //printf("gcd %d\n",gcd(x,y));
    return (x*y)/gcd(x,y);
}
int main()
{
    long long a,b,x,y;//,result;
    while(scanf("%I64d %I64d %I64d %I64d",&x,&y,&a,&b)==4)
    {
        //result=0;
        //printf("dsasd");
        x= lcm(x,y);
        if(x>b)
            printf("0\n");
        else
            printf("%I64d\n",(b/x)-((a-1)/x));
    }
    return 0;
}
