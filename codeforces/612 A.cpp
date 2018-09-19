#include <bits/stdc++.h>
//#define N 1000000
#define ll long long

using namespace std;


int main()
{
    char str[111];
    int n,p,q,ara[111],lenAra;
    while(scanf("%d %d %d\n",&n,&p,&q)==3)
    {
        scanf("%s",str);
        lenAra=0;
        int num=n,temp,cnt=0;
        if(num%p==0)
        {
            temp=num/p;
            cnt=temp;
            while(temp--)
                ara[lenAra++]=p;
        }
        else if(num%q==0)
        {
            temp=num/q;
            cnt=temp;
            while(temp--)
                ara[lenAra++]=q;
        }
        else
        {
            while(num>=p)
            {
                num-=p;
                cnt++;
                ara[lenAra++]=p;
                if(num%q==0)
                {
                    temp=num/q;
                    cnt+=temp;
                    num=0;
                    while(temp--)
                        ara[lenAra++]=q;
                }
            }
            if(num!=0)
            {
                printf("-1\n");
                continue;
            }

        }
        printf("%d\n",cnt);
        int j=0;
        for(int i=0;i<lenAra;i++)
        {
            while(ara[i]--)
            {
                printf("%c",str[j++]);
            }
            printf("\n");
        }

    }
    return 0;
}

