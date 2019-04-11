#include <bits/stdc++.h>

using namespace std;
//struct node {
//
//};
//int guest[1000011];
int main()
{
    int n;

    while(scanf("%d",&n)==1)
    {
        long long totalTime=0;
        int guestArrival=0;
        while(n--)
        {

            scanf("%d",&guestArrival);
            if(guestArrival>totalTime)
                totalTime= guestArrival+1;
            else
            {
                totalTime++;
            }
        }
        printf("%lld\n",totalTime-1);
    }

    return 0;
}
