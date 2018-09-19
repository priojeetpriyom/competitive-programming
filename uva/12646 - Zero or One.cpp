#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int main() {
    int a,b,c;
    while(scanf("%d %d %d",&a,&b,&c) == 3) {
        if (a==b || a==c) {
            if(b==a || b==c) {
                if (c==a || c == b) {
                    printf("*\n");
                }
                else printf("C\n");
            }
            else printf("B\n");
        }
        else printf("A\n");
    }
    return 0;
}
