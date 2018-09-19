#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

int mod (int x,int y,int n) {
    int z;
    if(y==0) return 1;
    else if(y%2 ==0) {
        z=mod(x,y/2,n) %n;
        return (z*z)%n;
    }
    else return ((x%n) * (mod(x,y-1,n) %n) %n);
}
int main ()
{
    int x,y,n;
    //for(n=0;n<100;n++) ara[n]=-1;
    while(scanf("%d %d %d",&x,&y,&n)==3) {
        printf("%d\n",mod(x,y,n));
    }
    return 0;
}

