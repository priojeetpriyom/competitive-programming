#include <bits/stdc++.h>

using namespace std;


int main ()
{
    int n;
    while(scanf("%d",&n)==1) {
        int mn=INT_MAX,x=55;
        while(n--) {
            int dist,cost;
            scanf("%d %d",&dist, &cost);
            if(dist<=55)
            {
                mn= min(mn,cost);
//                printf("dost %d cost %d\n",dist,cost);
            }
        }
        if(mn==INT_MAX)
            printf("Bad luck\n");
        else
            printf("%d\n",mn);
    }
    return 0;
}


