#include <bits/stdc++.h>
using namespace std;

int main()
{
    double a,b,c;
    while(scanf("%lf %lf %lf",&a, &b, &c)==3) {
        a= (a*c) - (b*c);
        printf("%.0lf\n",ceil(a/b));
    }
    return 0;
}
