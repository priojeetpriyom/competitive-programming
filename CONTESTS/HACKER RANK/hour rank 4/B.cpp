#include <bits/stdc++.h>

using namespace std;
//struct node {
//
//};
//int guest[1000011];
int main()
{
    int tCase;
    scanf("%d",&tCase);
    int Q[100011], bribe[100011];
    while(tCase--)
    {
        int n,cnt=0;
        bool continuee=true;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&Q[i]);
            bribe[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            if(Q[i]!=i)
            {
                if(Q[i]>i)
                {
                    if(bribe[Q[i]]==2)
                    {
                        continuee=false;
                        break;
                    }
                    bribe[Q[i]]++;
                }
                else
                {
                    if(bribe[i]==2)
                    {
                        continuee=false;
                        break;
                    }
                    bribe[i]++;
                }
                swap(Q[i],i);
                cnt++;
            }
        }
        if(continuee)
        {
            for(int i=1;i<=n;i++)
            {
            if(Q[i]!=i)
            {
                if(Q[i]>i)
                {
                    if(bribe[Q[i]]==2)
                    {
                        continuee=false;
                        break;
                    }
                    bribe[Q[i]]++;
                }
                else
                {
                    if(bribe[i]==2)
                    {
                        continuee=false;
                        break;
                    }
                    bribe[i]++;
                }
                swap(Q[i],i);
                cnt++;
            }
        }
            if(continuee)
            {
                for(int i=1;i<=n;i++)
            {
            if(Q[i]!=i)
            {
                if(Q[i]>i)
                {
                    if(bribe[Q[i]]==2)
                    {
                        continuee=false;
                        break;
                    }
                    bribe[Q[i]]++;
                }
                else
                {
                    if(bribe[i]==2)
                    {
                        continuee=false;
                        break;
                    }
                    bribe[i]++;
                }
                swap(Q[i],i);
                cnt++;
            }
        }
    }
        }
        if(continuee)
            printf("Too chaotic\n");
        else
            printf("%d\n",cnt);
    }
    return 0;
}
