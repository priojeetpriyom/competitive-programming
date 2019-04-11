#include <bits/stdc++.h>
//#define N 5
//#define ll long long
//int ara[N];
using namespace std;

int main()
{
    int n,mx,ara[5];
    while(scanf("%d",&n)==1)
    {
        ara[0]=0;ara[1]=0;ara[2]=0;ara[3]=0;
        for(int i=0;i<n;i++)
        {

            scanf("%d",&mx);
            ara[mx]++;
        }
        if(ara[1]>=ara[2] && ara[1]>=ara[3] && ara[1] !=0)
            printf("%d\n",ara[2]+ara[3]);
        else if(ara[2]>=ara[3] && ara[2]>=ara[1]&& ara[2] !=0)
            printf("%d\n",ara[1]+ara[3]);
        else
            printf("%d\n",ara[1]+ara[2]);
    }
    return 0;
}
