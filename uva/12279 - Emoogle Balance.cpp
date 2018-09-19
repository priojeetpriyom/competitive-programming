#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    int book,real,n,i,k=1;
    while (1) {
        k;
        scanf("%d",&n);
        if (n==0) break;
        else {
        book=0,real=0;
        while (n--) {
            scanf("%d",&i);
            if (i == 0) real++;
            else book++;
        }
        printf("Case %d: %d\n",k++,book-real);
    }
    }
    return 0;
}
