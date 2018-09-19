#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <climits>

using namespace std;


int main ()
{
    int t;
    scanf("%d",&t);
    t++;
    for(int i=1;i<t;i++)
    {
        int a,b,ara[20002],n,ct=0;
        memset(ara,0,sizeof(ara));
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d %d",&a,&b);
            if(ara[a]==0)
            {
                //printf("ok1\n");
                ara[a]=-1;
                ct++;
            }
            else if(ara[a]== -1)
            {
                //printf("ok1\n");
                ara[a]=-2;
                ct--;
            }
            if(ara[b]==0)
            {
                //printf("ok2\n");
                ara[b]=-1;
                ct++;
            }

            else if(ara[b]== -1)
            {
                //printf("ok2\n");
                ara[b]=-2;
                ct--;
            }
        }
        printf("Case %d: %d\n",i,ct);
    }

    return 0;
}

