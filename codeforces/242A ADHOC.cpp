#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,x,y,n,v[5000],p[5000],len;
    while(scanf("%d %d %d %d",&x,&y, &a,&b)==4)
    {
        len=0,n=0;
        //a=b;
//        if(b>a)
//            a=b;
        while(a<=x)
        {
            //printf("%d %d\n",a,b);
            for(int i=b;i<=y;i++)
            {

                if(a>i)
                {
                    n++;
                    v[len]=a;
                    p[len++]=i;
                }
                else break;
                //else break;
            }
//            if(b<y)
//                b++;
            a++;
        }
        //printf("x %d y %d a %d b %d\n",x,y, a,b);

        printf("%d\n",n);
        if(n>0)
            for(int i=0; i<len; i++)
                printf("%d %d\n",v[i],p[i]);
    }
    return 0;
}
