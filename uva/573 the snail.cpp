#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    double height,up,fatigue,down,k,sum,temp=0.0;
    while(scanf("%lf %lf %lf %lf",&height, &up, &down,&fatigue) && height!=0) {
        k=0,sum=0.0,fatigue=(fatigue/100)*up;
        while (1) {
            if (up>0) sum=sum + up;
            k++;
            if(sum>height) {
                printf("success on day %.0lf\n",k);
                break;
            }
            up=up-fatigue;
            sum=sum-down;

            if((sum<temp)) {
                printf("failure on day %.0lf\n",k);
                break;
            }
        }
    }
    return 0;
}
