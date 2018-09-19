#include <stdio.h>
int main()
{
    int t,i, j,k,sum,cas=0;

    scanf("%d",&t);
    while (t--) {


            sum=0;

            scanf("%d %d",&j,&k);


            if (j %2 == 0 && j!=k) {
                j++;
                for(;j<=k;j=j+2) sum = sum + j;
            }
            else {
                for(;j<=k;j=j+2) sum = sum + j;
            }

            printf("Case %d: %d\n",++cas,sum);



    }
    return 0;
}
