#include <iostream>
#include <cstdio>
#include <string.h>
int main ()
{
    double x,y,z,avg;
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%lf %lf %lf",&x,&y,&z);
            avg=(x+y)/3;
            printf("%0.0lf\n",((z*x)/avg)-z);
    }
   return 0;
}
