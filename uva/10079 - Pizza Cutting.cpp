#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int main() {
    long int n,piece,i;
    while (1) {
        scanf("%ld",&n);
        if(n>=0) {
            i=n+1;
            piece = (i * i/2) - i/2;
            printf("%ld\n",piece+1);
        }
        else break;
    }
    return 0;
}

