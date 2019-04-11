//#include <bits/stdc++.h>
#include<cstdio>
using namespace std;
//long long factorial(int n)
//{
//    //return (n<=2)? n: n*factorial(n-1);
//    if(n<=2)
//        return n;
//    return n* factorial(n-1);
//}
long long cCalculator(long long ara[])
{
    long long f1=0,f2=1,sum=0;
    for(int i=1;i<50;i++)
    {
        ara[i]=f1+f2;
        f2=f1;
        f1=ara[i];
    }
}

int main()
{
    int tCase,n;
    long long ara[50];
    cCalculator(ara);
    scanf("%d",&tCase);
    tCase++;
    for(int i=1;i<tCase;i++)
    {
        scanf("%d",&n);
        printf("Scenario #%d:\n",i);
//        long long sum = cCalculator(n+n,n);
//        sum= sum - cCalculator(n+n,n-1);
        printf("%I64d\n\n",ara[n+2]);
    }
    return 0;
}
