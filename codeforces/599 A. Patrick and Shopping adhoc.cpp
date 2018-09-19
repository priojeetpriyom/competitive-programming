#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <climits>
#include <string>
#include <stdlib.h>
//#define N 1000000

using namespace std;

int main()
{
    long long d01,d02,d12,a,b,c;
    while(scanf("%lld %lld %lld",&d01,&d02,&d12)==3)
    {
        long long sum=0;
        if(d01<d02)
        {
            sum=d01;
            a=d12+d02;
            b=d12+d12+d01;
            c=d01+d02+d02;
            a=min(a,b);
            a=min(a,c);
            sum+=a;
        }
        else {
            sum=d02;
            a=d12+d01;
            b=d12+d12+d02;
            c=d02+d01+d01;
            a=min(a,b);
            a=min(a,c);
            sum+=a;

        }
        cout<<sum<<endl;
    }
    return 0;
}
