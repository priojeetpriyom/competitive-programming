#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int i,j,k=0,n,maxx;
    int ara[1000],lis[1000];
    scanf("%d",&n);
    for (i=0;i<n;i++) {
        scanf("%d",&ara[i]);
    }
    for (i=0;i<n;i++) {
        lis[i] =1;
    }
    for (i=0;i<n;i++) {
        for (j=i;j>=0;j--) {
            if((ara[i] > ara [j]) && (lis[j] +1 > lis[i])) {
                lis[i] = lis[j] +1;

            }
        }

    }
    maxx=0;
    for (j=0;j<n;j++) {
        if (lis[j] >maxx) maxx = lis[j];
    }
    i=1;
    printf("%d\n",maxx);
     for (j=n-1;j>=0;j--) {
        if (lis[j] == maxx){
            printf("%d ",ara[j]);
            maxx=maxx-1;
            if(maxx == 0)break;
        }
    }
    // printf("\n");

    return 0;
}
