#include <bits/stdc++.h>

using namespace std;

int main()
{
    int len,n,k;
    while(scanf("%d %d",&n,&k)==2)
    {
        int ara[503] [503];
        int x=k-1,y;
        long long mx=0;
//        for(int i=0; i<30; i++)
//            ara[i]=0;
        y=1;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<x; j++)
                //scanf("%d",&ara[i] [j]);
            ara[i] [j]= y++;
        }
        int sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=y;
            for(int j=x; j<n; j++)
                //scanf("%d",&ara[i] [j]);
            ara[i] [j]= y++;
        }
//        for(int i=0; i<n; i++)
//        {
//            //
//            //sort(ara[i],ara[i]+n);
//            for(int j=0; j<n; j++)
//                printf("%d ",ara[i] [j]);
//            printf("\n");
//        }
//        long long res=ara[0];
        //
        printf("%d\n",sum);
        for(int i=0; i<n; i++)
        {
            //
//            sort(ara[i],ara[i]+n);
            for(int j=0; j<n; j++)
                printf("%d  ",ara[i] [j]);
            printf("\n");
        }
//        if(mx==0)
//            mx=1;
        //printf("%I64d\n",res);
    }
    return 0;
}
