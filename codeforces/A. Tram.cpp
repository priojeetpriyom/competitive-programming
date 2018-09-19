#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;

int main ()
    {
    int n,x,y,maxx,passenger;
    while (scanf("%d",&n)==1) {
        maxx=passenger=0;
        while (n--) {
            scanf("%d %d",&x,&y);
            passenger+=y-x;
            if(passenger>maxx) maxx=passenger;
        }
        printf("%d\n",maxx);
    }
    return 0;
    }
