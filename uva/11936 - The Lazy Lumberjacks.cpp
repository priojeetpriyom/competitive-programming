#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    int n, a, b, c;
    while (scanf("%d",&n) == 1) {
        while(n--) {
            scanf("%d %d %d", &a, &b, &c);
            if (a+b>c && a+c>b && b+c>a) printf("OK\n");
            else printf("Wrong!!\n");
        }
    }
    return 0;
}

