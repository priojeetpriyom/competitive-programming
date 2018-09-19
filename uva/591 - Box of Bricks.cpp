#include <iostream>
#include <cstdio>
using namespace std;
int main ()
{
    int n,ara[1000],i,avg,k,j=1;
    while (1) {
        avg=0,k=0;
        scanf("%d",&n);
        if(n==0) {
            break;
        }
        else {
            for (i =0;i<n;i++) {
                scanf("%d",&ara[i]);
            }
            for (i=0;i<n;i++) {
            avg = avg + ara[i];
            }

            avg = avg/n;
            for (i=0;i<n;i++) {
                if(ara[i] > avg) {
                k=k+ (ara[i] - avg);
                }
            }
            printf("Set #%d\n",j++);
            printf("The minimum number of moves is %d.\n\n",k);
            }
        }
    return 0;
}
