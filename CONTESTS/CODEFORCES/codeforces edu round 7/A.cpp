#include <bits/stdc++.h>

using namespace std;
//int ara[100001];
//long long a,b,c,d,e,f;

int main()
{
    //a=0,b=1,c=2,d=3,e=4,f=5;
    int tCase;
    long long n;
    long long pod,sthan;
    while(scanf("%I64d",&n)==1)
    {
        pod= (float) (-1+sqrt(abs(1-4*2*n)))/2;
        //printf("%I64d\n",pod);
        sthan = pod*(pod+1)/2;
        sthan= n- sthan;
        if(sthan==0)
        printf("%I64d\n", pod);
        else
            printf("%I64d\n", sthan);
    }
    return 0;
}
