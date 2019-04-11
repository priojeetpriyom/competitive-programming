#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <climits>
#include <string>
#include <stdlib.h>
//#define N 1000000

using namespace std;

int main()
{
    int tcase,n,leaked[11],not_leaked[11],l,nl,d,ls,sum;
    char s,r;
    scanf("%d",&tcase);
    while(tcase--)
    {
        for(int i=0;i<11;i++)
        {
            leaked[i]=0;
            not_leaked[i]=0;
        }
        scanf("%d\n",&n);
        l=0,nl=0,ls=0;
        while(n--)
        {
            scanf("%d %c %c",&d,&s,&r);
            if(r=='c')
            {
                if(s==49)
                    leaked[d]+=1;
            }
            else if(s==48)
                not_leaked[d]+=1;
        }
        sum=0;
        for(int i=2; i<11; i++)
            {
                if(leaked[i]!=0)
                {
                    for(int j=1;j<i;j++)
                        sum+=not_leaked[j];
                        sum*=leaked[i];
                }

            }

        printf("%d\n",sum);
    }
    return 0;
}

