#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int main() {
    long int i,j,k;
    int str[10000];
    while (1) {
    scanf("%ld",&i);
    if (i == 0) break;
    else {
        j=0,k=0;
        printf("The parity of ");
        while(i>0) {
            if (i%2==1) {
                str[j++] = 1;
                k++;
            }
            else {
                str[j++] = 0;
            }
            i=i/2;
        }
        while (--j>=0) {
            printf("%d",str[j]);
        }
        printf(" is %ld (mod 2).\n", k);
    }

    }
    return 0;
}
