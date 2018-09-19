#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
int main() {
    unsigned long int n1,n2;
    int carry,k;
    while (scanf("%lu %lu",&n1,&n2)==2) {
        carry=0,k=0;
        if (n1==0 && n2==0) break;
            while (n1>0 || n2>0) {
                if ((n1%10)+(n2%10)+k>9) {
                    carry++;
                    k=1;
                    n1/=10,n2/=10;
                }
                else n1/=10,n2/=10,k=0;
            }
            if(carry==0)
                printf("No carry operation.\n");
            else if(carry==1)
                printf("%d carry operation.\n",carry);
            else
                printf("%d carry operations.\n",carry);
}
    return 0;
}

