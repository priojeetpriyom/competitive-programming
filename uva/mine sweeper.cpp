#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
int main ()
{
    int r,c,m,n,ct,i=1;
    char str[110] [110];
    while(scanf("%d %d",&m,&n) == 2)
    {
        memset(str,0,sizeof(str));
        if(m==0 && n==0) break;
        for(r=0; r<m; r++)
            scanf("%s",str[r]);
        if(i>1) printf("\n");
        printf("Field #%d:\n",i++);
        for(r=0; r<m; r++)
        {
            for(c=0; c<n; c++)
            {
                if(str[r] [c] == '*') {
                    printf("*");
                    continue;
                }
                ct=0;
                if(r>0)
                {
                    if(c>0 && str[r-1] [c-1] == '*') ct++;
                    if(str[r-1] [c] == '*') ct++;
                    if(c+1<n && str[r-1] [c+1] == '*') ct++;
                }
                if(c>0 && str[r] [c-1] == '*') ct++;
                if(c+1<n && str[r] [c+1] == '*') ct++;
                if(r+1<m)
                {
                    if(c>0 && str[r+1] [c-1] == '*') ct++;
                    if(str[r+1] [c] == '*') ct++;
                    if(c+1<n && str[r+1] [c+1] == '*') ct++;
                }
                printf("%d",ct);
            }
            printf("\n");
        }

    }
    return 0;
}
