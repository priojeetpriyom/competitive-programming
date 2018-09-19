 #include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
    double m1,m2,m3,area;
    while(scanf("%lf %lf %lf",&m1,&m2,&m3) ==3) {
        area=(m1+m2+m3)/2;
        area=(4.000000/3.0000000)*sqrt(area*(area-m1)*(area-m2)*(area-m3));
        if(area>0) printf("%.3lf\n",area);
        else printf("-1.000\n");
    }
    return 0;
}
