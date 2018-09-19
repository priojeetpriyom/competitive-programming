 #include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    long long int n,i,k,t,n1,n2,sum;
    scanf("%lld",&t);
    while (t--) {
        scanf("%lld",&n);
        n1=n;
        k=0;
        while (1) {
            n2=0;
            n=n1;
            while (n>0) {
                n2 = n2*10+(n%10);
                n/=10;
        }
            if (n1==n2) break;
            else {
            sum = n1+n2;
            n1=sum;
            }
            k++;
   }
        printf("%lld %lld\n",k,sum);
    }
    return 0;
}
