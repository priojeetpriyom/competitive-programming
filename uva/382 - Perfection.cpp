#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main ()
{
    int n[110],i,j,k=0,root,sum,space;

    while (1) {
        scanf("%d",&n[k]);
        if (n[k++]==0) break;
    }
    printf("PERFECTION OUTPUT\n");
        for(j=0;j<k-1;j++) {
            if(n[j]>9999) space=0;
            else if(n[j]>999) space=1;
            else if (n[j]>99) space =2;
            else if(n[j]>9) space=3;
            else space=4;
            if(n[j]>1) sum=1;
            else sum=0;

            root=sqrt(n[j]) +1;
            for (i=0;i<space;i++) printf(" ");
            for(i=2;i<root;i++) {
                //printf("sum %d\n",sum);
                if(n[j]%i==0 && (n[j]/i)>1) {
                    //if(i!=n[j]/i)
                    sum+=i+(n[j]/i);
                    //printf("i %lld n/i %lld sum %lld\n",i,n[j]/i,sum);
                    //else sum+=i;
                }
            }
            if(sum<n[j]) printf("%d  DEFICIENT\n",n[j]);
            else if(sum>n[j]) printf("%d  ABUNDANT\n",n[j]);
            else printf("%d  PERFECT\n",n[j]);
        }
    printf("END OF OUTPUT\n");
    return 0;
}
