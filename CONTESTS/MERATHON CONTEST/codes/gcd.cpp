#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
int gcd(int a,int b)
{
    //printf("i %d j %d",a,b);
    int rem=1;
    while(rem!=0)
    {
        rem=a%b;
        a=b;
        b=rem;

    }

    return a;
}

int main ()
{
    int n,i,j,sum;
    while(1) {
        scanf("%d",&n);
        if(n==0) break;
        sum=0;
        for(i=1;i<n;i++)
            for(j=i+1;j<=n;j++)
            {
                sum+=gcd(j,i);
            }
        printf("%d\n",sum);
    }
    return 0;
}
