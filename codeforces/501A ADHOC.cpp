#include <bits/stdc++.h>
using namespace std;

int main()
{
    double a,b,c,d,misha,vasya;
    while(scanf("%lf %lf %lf %lf",&a,&b,&c,&d)==4)
    {
        double x,y;
        x=(3*a)/10.0;
        y= a - ((a*c)/250);
        misha=max(x,y);
        x=(3*b)/10.0;
        y= b - ((b*d)/250);
        vasya=max(x,y);
        if(vasya==misha)
            printf("Tie\n");
        else if(vasya<misha)
            printf("Misha\n");
        else
            printf("Vasya\n");
    }
    return 0;
}
