#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    int i;
    long long genarations,ancestors,sum,f1,f2;
    while (scanf("%lld",&genarations) == 1 && genarations!= 0) {
        i=0,ancestors=0,f1=0,f2=1;
        if (genarations==1) printf("1\n");
        else {
            for(;i<genarations;i++) {
                ancestors=f1+f2;
                f1=f2;
                f2=ancestors;
            }
            printf("%lld\n",ancestors);
        }

    }
    return 0;
}
