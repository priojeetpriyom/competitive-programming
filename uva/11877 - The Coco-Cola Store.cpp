#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    int bottle,k;
    while (1) {
            k=0;
        scanf("%d",&bottle);
        if (bottle == 0) break;
        else {
            bottle+=1;
            while(bottle > 2) {
                bottle -=2;
                k++;
            }
            printf("%d\n",k);
        }
    }
    return 0;
}
