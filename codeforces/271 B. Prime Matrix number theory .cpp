#include <bits/stdc++.h>
using namespace std;
bool notPrime[1000001];
int row, col, ara[501] [501];
int main()
{
//    freopen("myOutput.txt","w",stdout);
    //freopen("myInput.txt",") ;;;we
    for(int i=4; i<1000001; i+=2)
        notPrime[i]=true;
    notPrime[0]= notPrime[1]=true;
    for(int i=3; i<1000001; i+=2)
    {
        if(!notPrime[i])
            for(long long x=(long long) i*i; x<1000001; x+=i)
                notPrime[x]=true;
    }

    scanf("%d %d",&row, &col);
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            scanf("%d",&ara[i] [j]);

    int mn=INT_MAX;
    for(int i=0; i<row; i++)
    {
        int cnt=0;
        for(int j=0; j<col; j++)
        {
            if(notPrime[ara[i] [j] ])
            {
                for(int k= ara[i] [j]; ; k++)
                {
                    if(!notPrime[k])
                    {
                        cnt+= k- ara[i] [j];
                        break;
                    }
                }

            }
        }
        if(cnt<mn)
            mn=cnt;
    }
    for(int j=0; j<col; j++)
    {
        int cnt=0;
        for(int i=0; i<row; i++)
        {
            if(notPrime[ara[i] [j] ])
            {
                for(int k= ara[i] [j]; ; k++)
                {
                    if(!notPrime[k])
                    {
                        cnt+= k- ara[i] [j];
                        break;
                    }
                }
            }
        }
        if(cnt<mn)
            mn=cnt;
    }
    printf("%d\n",mn);
    return 0;
}


