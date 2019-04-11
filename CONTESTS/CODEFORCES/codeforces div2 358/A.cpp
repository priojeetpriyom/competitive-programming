#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int n,m;
    long long cnt=0;
    scanf("%d %d",&n,&m);
    if(n>m)
        swap(n,m);
    for(int i=1; i<=n; i++)
    {
        int x = i%5;
        if(x==0)
        {
            cnt+= (m/5);
        }
        else
        {

            if(x+m<5)
            {

            }
            else
                {
                    x= (5-x);
                    x= m-x;
                    cnt+= (x/5)+1;
                }
        }
    }
    printf("%I64d\n",cnt);
}


