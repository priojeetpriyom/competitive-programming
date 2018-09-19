#include <bits/stdc++.h>

using namespace std;

int main()
{
    int totalDust,dustForEach;
    int tCase,n;
    scanf("%d",&tCase);
    tCase++;
    for(int i=1;i<tCase;i++)
    {
        scanf("%d",&n);
        int totalDust=0,dustForEach=0;;
        while(n--)
        {
            scanf("%d",&dustForEach);
            if(dustForEach>0)
                totalDust+=dustForEach;
        }
        printf("Case %d: %d\n",i,totalDust);
    }
    return 0;
}
