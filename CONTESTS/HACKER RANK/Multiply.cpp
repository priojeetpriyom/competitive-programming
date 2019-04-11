#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <climits>
#define INT_MAX;

using namespace std;


int main() {
    int n;
    int q,x;
    while (scanf("%d %d",&n,&q)==2) {
    while(q--)
    {
        long long sum=0;
        scanf("%d",&x);
        int temp=n;
        for(int i=1;i<x;i++)
            n+=temp;

        int root= sqrt(n)+1;
        //printf("n %d x %d\n",n,x);
        for(int i=1;i<root;i++)
        {
            if(n%i==0)
            {
                sum+=i;
                temp=n/i;
                if(i!=temp)
                    sum+=temp;
//                if(sum>1000000007)
//                    sum=sum%1000000007;
            }
        }
            printf("%lld\n",sum%1000000007);
    }
    }
    return 0;
}


