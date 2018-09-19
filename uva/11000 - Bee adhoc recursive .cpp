#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
long long ara[100];

long long bee_count(long long n)
{
    if(n<=0) return 0;
    else if(n==1) return 1;
    else
    {
        if(ara[n] != -1)
            return ara[n];

        else
        {

            ara[n]= bee_count(n-1)+bee_count(n-2);
            return ara[n];
        }
    }

}
int main ()
{
    long long n,male=0,total=0,female=1;
    while(1)
    {

        scanf("%lld",&n);

        if(n== -1) break;
        memset(ara,-1,sizeof(ara));
        male=bee_count(n+2)-1;
        total=bee_count(n+3)-1;

        printf("%lld %lld\n",male,total);

    }
    return 0;
}

