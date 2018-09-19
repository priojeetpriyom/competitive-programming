#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    int a,b,c;
    while (1) {
        scanf("%d %d %d", &a, &b, &c);
        if (a==0) break;
        else {
            if ((a== sqrt(b*b+c*c)) || (b== sqrt(a*a+c*c)) || c== sqrt(b*b+a*a)) printf("right\n");
            else printf("wrong\n");
        }
    }
    return 0;
}
