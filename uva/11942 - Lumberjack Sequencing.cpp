#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    int i,k,t,n=10,ara[20],l=0;


    while (scanf("%d",&t)==1) {
    while(t--) {
        for (i=0;i<n;i++) scanf("%d",&ara[i]);
        if (l==0) {
            l++;
            printf("Lumberjacks:\n");
        }
        if (ara[1] > ara[0]) {
            for (i=2;i<n;i++) {
                if (ara[i]>ara[i-1]) k=1;
                else {
                    k=0;
                    break;
                }
            }
        }
        else {
                for (i=2;i<n;i++) {
                if (ara[i]<ara[i-1]) k=1;
                else {
                    k=0;
                    break;
                }
            }
        }
        if (k==1) printf("Ordered\n");
        else printf("Unordered\n");
    }
}
    return 0;
}
