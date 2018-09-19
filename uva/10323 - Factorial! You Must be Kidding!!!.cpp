#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    long long fact,n,k;
    while (scanf("%lld",&n)==1) {
        fact=n,k=1;
        if(n<0 && n%2==0 || n>=0 && n<8) printf("Underflow!\n");
        else if (n<0 && n%2!=0) printf("Overflow!\n");
        else {
        while(n-1>0) {
            --n;
            if(fact>6227020800) {
                printf("Overflow!\n");
                k=0;
                break;
            }
            else fact*=n;
        }
            if (k==1) printf("%lld\n",fact);
    }
    }
    return 0;
}
