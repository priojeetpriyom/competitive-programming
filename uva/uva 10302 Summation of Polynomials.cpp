#include <cstdio>
#include <iostream>
using namespace std;
int qube(long int n,long int sum) {
    int i =0;
    if (n == 0) return sum;
    else sum = sum+n*n*n;
    qube((n-1),sum);

}

int main ()
{
    long int n;

    while (scanf("%ld",&n) == 1) printf("%ld\n",qube(n,0));
    return 0;

}
