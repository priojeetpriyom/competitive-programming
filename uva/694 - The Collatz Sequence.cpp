#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    long int a,lim,i,j=1,k,n;
    while (1) {
        scanf("%ld %ld", &a, &lim);
        if (a<0) break;
        else {
            n=a;
            k=1;
            while (n!=1 && n<=lim) {
                k++;
                if (n%2 == 1) {
                    n = 3*n + 1;
                }
                else {
                    n = n/2;
                }
                if (n>lim) k--;
            }
            printf("Case %ld: A = %ld, limit = %ld, number of terms = %ld\n", j++, a, lim,k);
        }
    }
    return 0;
}
