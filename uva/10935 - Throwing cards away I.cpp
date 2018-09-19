 #include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
    int i,j,n,ara[150],discard;
    while(1) {
        discard=0;
        scanf("%d",&n);
        if(n==0) break;
        for(i=0;i<n;i++) ara[i] = i+1;
        j=n;
        --n;
        i=0;
        printf("Discarded cards:");
        while (discard<n) {
            if(i%2==0) {
                printf(" %d",ara[i]);
                discard++;
                if(discard<n) printf(",");
            }
            else {
                ara[j++]=ara[i];
            }

            i++;
        }
        printf("\n");
        printf("Remaining card: %d\n",ara[j-1]);
    }
    return 0;
}
