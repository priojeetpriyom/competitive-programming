#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    int t;
    double high,red;
    int len;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&len);
        red =acos(-1)* (4 * len * len)/100;
        printf("%.2lf ",red);
        high = len * .6;
        printf("%.2lf\n",(high*len)-red);
    }
    return 0;
}
