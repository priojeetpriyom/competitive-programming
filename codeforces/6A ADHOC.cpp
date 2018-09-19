#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ara[10],a,b,c,d,temp;
    while(scanf("%d %d %d %d",&a,&b,&c,&d)==4)
    {
        ara[0]=a;
        ara[1]=b;
        ara[2]=c;
        ara[3]=d;
        sort(ara,ara+4);
        a=ara[0];
        b=ara[1];
        c=ara[2];
        d=ara[3];
        if(b+a>d)
        {
            printf("TRIANGLE\n");
        }
        else if(b+c>d)
        {
            printf("TRIANGLE\n");
        }
        else if(a+c>d)
        {
            printf("TRIANGLE\n");
        }
        else if(a+b>c)
        {
            printf("TRIANGLE\n");
        }
        else if(b+a==d)
        {
            printf("SEGMENT\n");
        }
        else if(b+c==d)
        {
            printf("SEGMENT\n");
        }
        else if(a+c==d)
        {
            printf("SEGMENT\n");
        }

        else if(a+b==c)
        {
            printf("SEGMENT\n");
        }
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}
