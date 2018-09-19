#include <iostream>
#include <cstdio>
int qube(long int n,long int sum,long int k) {
    int i =0;
    if (n == 0) return sum;
        for (; i<(n*n); i++) {
              k = n+k;
            }
            sum = sum+k;
            qube((n-1),sum,0);

}

int main ()
{
    long int n=500;

    //while (scanf("%ld",&n))
    printf("%ld\n",qube(n,0,0));

}
