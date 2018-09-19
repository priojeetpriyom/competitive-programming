#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    long long a,b,c,d,i,j,k,l,sum;
    while(scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&l)==5 && d>0) {
        k=0;
        for(i=0;i<=l;i++) {
            sum= a * i*i + b * i+c;
            if (sum%d==0) k++;
        }
        printf("%lld\n",k);
    }
    return 0;
}
