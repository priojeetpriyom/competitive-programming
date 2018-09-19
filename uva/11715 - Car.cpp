#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    double u,t,v,s,a,velo,uelo,time;
    int i=1,n;
    while (1) {
        scanf("%d",&n);
        if (n == 0) break;
        else {
            if (n == 1) {
                scanf("%lf %lf %lf",&u,&v,&t);
                printf("Case %d: %.3lf %.3lf\n",i++,((u+v)*t)/2 ,((v-u)/t));
            }
            else if (n == 2) {
                scanf("%lf %lf %lf",&u,&v,&a);
                time = ((v-u)/a);
                printf("Case %d: %.3lf %.3lf\n",i++,((u+v)*time)/2, time);
            }
            else if (n == 3) {
                scanf("%lf %lf %lf",&u,&a,&s);
                velo= sqrt(pow(u,2) + 2*a*s);
                printf("Case %d: %.3lf %.3lf\n",i++, velo, ((velo-u)/a));
        }
            else{
                scanf("%lf %lf %lf",&v,&a,&s);
                uelo = sqrt(pow(v,2) -2*a*s);
                printf("Case %d: %.3lf %.3lf\n",i++, uelo,((v-uelo)/a));
        }
        }
        }
    return 0;
}

