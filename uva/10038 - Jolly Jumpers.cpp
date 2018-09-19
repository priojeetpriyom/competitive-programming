#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
    int i,n,jumpers[3010],diff,check[3010];
    while(scanf("%d",&n) ==1) {
        for(i=0;i<n;i++) scanf("%d",&jumpers[i]);
        for(i=0;i<n-1;i++) check[i] = i+1;
        //for(i=0;i<n-1;i++) printf("%d\n",check[i]);
        for(i=1;i<n;i++) {
            diff=abs(jumpers[i]-jumpers[i-1]);
            //printf("diff %d check %d\n",diff,check[diff-1]);
            if(diff<1 || diff>=n) {
                printf("Not jolly\n");
                n=0;
                break;
            }
            else if(diff== check[diff-1]) check[diff-1]=0;
        }
        if(n>0) {
        for(i=1;i<n;i++) if(check[i]!=0)  {
            printf("Not jolly\n");
            n=0;
            break;
        }
        if(n>0) printf("Jolly\n");
    }
    memset(check,0,sizeof(check));
    }
    return 0;
}
