#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    long long int i,j,k,n,ara[100000],rim;
    while (scanf("%lld",&n)==1 && n>=0) {
        if (n==0) printf("0\n");
        else {
            k=0;
            i=n;
            while(i>0) {
                ara[k++] = i%3;
                i=i/3;
            }
            for (j=k-1;j>=0;j--) printf("%lld",ara[j]);
            printf("\n");
    }
    }
    return 0;
}
