#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    long long int n,f1,f2,sum,i,j,k;
    while (scanf("%lld",&n) == 1 && n!=0) {
        sum=0,i=0,f1=0,f2=1;
        while(++i<=n) {
            sum =f1+f2;
            f1=f2;
            f2=sum;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
