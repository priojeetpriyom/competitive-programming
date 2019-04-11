#include<bits/stdc++.h>

using namespace std;
typedef long long ll;




int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);


    int t;
    scanf("%d", &t);
        double x, y, r;

    while(t--) {
        scanf("%lf %lf %lf", &x, &y, &r);
//        printf("x %lf y %lf\n",x , y);
//        printf("xx %lf\n", x*x+y*y);
        double dist = sqrt( round(x*x) + round(y*y) );
//        printf("dist %lf\n", dist);
        double xa = r - dist;
        double  xb = r+ dist;
        if(xa>xb) swap(xa, xb);
         printf("%.2lf %.2lf\n", xa, xb);
    }

    return 0;

}


