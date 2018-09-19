#include <iostream>
#include <cstdio>
using namespace std;
int main ()
{
    int t,i=1;
    double c,f;
    scanf("%d",&t);
    while(i<=t) {
        scanf ("%lf %lf",&c,&f);
        f=f+((1.80*c))+32;
        c=((f-32)*5)/9;
        printf("Case %d: %.2lf\n",i,c) ;
        i++;
    }
    return 0;
}
