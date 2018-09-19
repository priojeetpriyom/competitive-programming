#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    int m,n,k;
    while(scanf("%d %d",&m,&n)==2) {
        k=m/2;
        if(n>1) k=k+ k*(n-1);
        if(m%2==1 && n>1) k+= n/2;
        printf("%d\n",k);
    }
    return 0;

}
