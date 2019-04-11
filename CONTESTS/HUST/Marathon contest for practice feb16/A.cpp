#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323846
int main()
{
    double n,R,r,circle=2*PI;
    while(scanf("%lf %lf %lf",&n, &R, &r)==3)
    {
        if(r>R)
            printf("NO\n");
        else if(r==R)
        {
            if(n>1)
                printf("NO\n");
            else
                printf("YES\n");
        }
        else if(R-r<=r)
        {
            if(n>2)
                printf("NO\n");
            else
                printf("YES\n");
        }
        else
        {
            R-=r;
//            double c= sqrt()

            R = n*acos(((2*R*R) - (r*r*4))/ (2*R*R));
            //printf("%lf\n",R);
            if(R<=circle)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
