
#include <bits/stdc++.h>

using namespace std;

int main()
{
    double radius,pi = 2 * acos (0.0);
    int tCase;
    scanf("%d",&tCase);
    tCase++;
    for(int i=1;i<tCase;i++)
    {
        scanf("%lf",&radius);
        printf("Case %d: %.2lf\n",i,radius*radius*(4-pi));
    }
    return 0;
}
