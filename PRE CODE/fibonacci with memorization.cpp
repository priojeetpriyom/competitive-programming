#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <stdlib.h>
using namespace std;
long long int ara[100];

long long int fibo (long long int n) {
    if(n<2) return n;
    else if(ara[n] != -1) return ara[n];
    else {
        ara[n]= fibo(n-1)+fibo(n-2);
        return ara[n];
    }
    //else return fibo(n-1) +fibo(n-2);
}
int main ()
{
    long long int n;
    for(n=0;n<100;n++) ara[n]=-1;
    while(scanf("%lld",&n)==1) {
        printf("%lld\n",fibo(n));
    }
    return 0;
}
