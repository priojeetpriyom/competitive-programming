#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,p1,d,p2;
    while(scanf("%d %d",&a,&b)==2)
    {
        p1=0,p2=0,d=0;
        for(int i=1;i<7;i++)
        {
            if(abs(i-a)<abs(i-b))
            p1++;
            else if(abs(i-a)>abs(i-b))
                p2++;
            else
                d++;
        }
        printf("%d %d %d\n",p1,d,p2);
    }
    return 0;
}
