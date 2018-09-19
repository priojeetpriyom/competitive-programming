#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    long long int a, b, c, d;
    int i, t;
    while (scanf("%d",&t) == 1) {
        for (i=0;i<t;i++) {
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        if (a==b && b==c && c==d) printf("square\n");
        else if ((a==c && b==d) || (a==b && c==d) || (b==c && a==d) ) printf("rectangle\n");
        else if ((a+b+c>d) && (a+b+d>c) && (a+c+d>b) && (b+c+d>a) ) printf("quadrangle\n");
        else printf("banana\n");
    }
    }
    return 0;
}
