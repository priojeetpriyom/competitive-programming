#include <stdio.h>
int main()
{
    int n,i, j,k,sum,cas=0;
    int ara[100];

    while (scanf("%d",&n) == 1) {
    j=n;
    for (i = 0;i<n;i++) {
        ara[i] = i+1;
        }
    for (k = 0;k<2*n-1;k+=2) {
        if (k %2 ==0) {
            printf("%d\n ",ara[i]);
        }
        else {
            ara[j] = ara[k+1];
            j++;
        }
        if (j == 2*n-2) printf("%dmm\n",ara[2*n-5]);
    }
    }



    return 0;
}
