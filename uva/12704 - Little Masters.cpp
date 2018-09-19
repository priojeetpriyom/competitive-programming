#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
    float r,x,y;
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%f %f %f",&x,&y,&r);
        x=sqrt(x*x+y*y);
        printf("%.2f %.2f\n",r-x,r+x);
    }
    return 0;
}
