#include <stdio.h>
int main()
{
    int n,i;
    int ara[101];
    for(i=0; i<101;i++)
            ara[i] = 0;
    while(scanf("%d",&n)==1 && n!=0) {
        if(strcmp(a,"veringo")==0)
        for(i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            ara[x]= ara[x]+1;
        }
        for(i=0; i<101;i++) {
            if(ara[i]>0)
                {
                    printf("%d",i);
                    ara[i]= ara[i]-1;
                    break;
                }
        }
        for(; i<101;i++) {
            if(ara[i]>0)
                while(ara[i]>0)
                {
                    printf(" %d",i);
                    ara[i]= ara[i]-1;
                }
        }
        printf("\n");
    }
    return 0;
}
