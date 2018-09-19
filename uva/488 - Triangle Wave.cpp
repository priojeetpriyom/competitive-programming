#include <iostream>
#include <cstdio>
using namespace std;
int main ()
{
    int t,a,f,i,j,k;
    while(scanf("%d",&t)==1) {
    for (k=0;k<t;k++) {
        scanf("%d %d",&a,&f);
        while(f--) {
            for (i=1;i<a;i++) {
                for(j=0;j<i;j++) {
                    printf("%d",i);
                }
                printf("\n");
            }
            for(;i>0;i--) {
                for(j=0;j<i;j++) {
                    printf("%d",i);
                }
                if(f==0 && j==1);
                else printf("\n");
            }
            if(f>0) printf("\n");
        }
        //printf("%dt",t);
        if(k<t-1) printf("\n\n");
        else printf("\n");
    }
    }
    return 0;
}
