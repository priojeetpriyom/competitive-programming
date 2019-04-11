#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("myOutput.txt","w",stdout);

    int t;
    while(scanf("%d",&t)==1 && t!=0) {
        double mx=INT_MIN;
        int mx_volume=0;
        while(t--) {
            double l,w,h;
            scanf("%lf %lf %lf",&l,&w,&h);
            int volume = (int)(l*w*h);
            h+=h;
            double f = 9.8 - (9.8/h);
            if(f>mx) {
                mx=f;
                mx_volume = volume;

            }
            else if(f==mx)
                mx_volume = max(mx_volume,volume);
        }
        printf("%d\n",mx_volume);
    }
    return 0;
}

