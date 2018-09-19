#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
    int ara[11111];
    int n,m,t,i,j,ct=0,flag=1,priority[101],pos=0;
    int endd= i,start=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        ct=0;
        for(i=0; i<n; i++) scanf("%d",&ara[i]);

        for(i=0; i<n; i++) priority[i] = ara[i];
        int p=i-1;
        int endd= i,start=0;
        pos=0;
        sort(priority,priority+i);
        //printf("prio max %d\n",priority[p]);
        //printf("%d\n",priority[1]);
        while(priority[pos] != ara[m]) pos++;
        //printf("prio pos %d\n",priority[pos]);
        while(priority[pos] == priority[pos+1]) pos++;
        while(p>pos)
        {
            for(i=start; i<endd; i++)
            {
                if(ara[i] == priority[p])
                {
                    ct++;
                    if(i<m);
                    //else if(i==endd-1 || i==start);
                    else m+=endd-start;
                    p--;
                    //printf("changing m %d end %d\n",m,endd);
                    break;
                }
            }
            for(j=start; j<i; j++)
            {
                ara[endd++]= ara[j];
            }
            start=i+1;
        }
        //printf("m %d\n",m);
        //for(i=start;i<endd;i++) printf("ara %d ",ara[i]);
        //printf("\n ara %d m %d start %d ct %d\n",ara[m],m,start,ct);
        for(i=start; i<=m; i++) if(ara[i] == ara[m]) ct++;
        //}
        //for(i=start;i<endd;i++) ct++;//if(priority[m]=ara[i])
        printf("%d\n",ct);
    }
    return 0;
}
