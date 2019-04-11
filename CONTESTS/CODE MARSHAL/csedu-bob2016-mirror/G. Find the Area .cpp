#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("myOutput.txt","w",stdout);

    int tcase;
    scanf("%d",&tcase);

    for(int t=1; t<=tcase; t++) {
        double n;
        scanf("%lf",&n);
        double triangle = n*n;
        double circle = acos(-1)*(n/2)*(n/2);
        printf("%.2lf\n",triangle-circle);

    }

    return 0;
}


