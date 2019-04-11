#include <bits/stdc++.h>
//char gogol[100001], papple[31];
using namespace std;

int main()
{
    int ara[1011], height[1011];
    int n;

    while(scanf("%d",&n)==1)
    {
        n++;
        ara[0]= ara[n]= ara[INT_MAX];
        for(int i=1; i<n; i++)
            scanf("%d",&ara[i]);
        //printf("oka\n");
        int x,mx=0;
        height[0]= 0;
        for(int i=1; i<n; i++)
        {
            if(ara[i]>= ara[i-1])
                height[i]= height[i-1]+1;
            else
                height[i]= 1;
        }
//
//        for(int i=1; i<n; i++)
//            printf("%d ",height[i]);
        //a[n] = INT_MAX;
        mx= height[1];
        x=0;
//        printf("n %d\n",n);
        for(int i=n-2; i>=1; i--)
        {

            if(ara[i]>= ara[i+1])
            {
                height[i]+=(++x);
                if(height[i]>mx)
                {
                    mx=height[i];
                    //x=height[i];
                }
            }
            else x=0;
//            else
//                height[i]= 0;
        }
        if(height[n-1]>mx)
            mx=height[n-1];
//
//        printf("\n");
//        for(int i=1; i<n; i++)
//            printf("%d ",height[i]);

//        for(int i=1;i<n; i++)
        printf("%d\n",mx);
    }
    return 0;
}
