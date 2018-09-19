#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ara[30];
    char str[200000];
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=0;i<27;i++)
            ara[i]=0;
        scanf("\n%s",str);
        int lenStr= strlen(str),neededKeys=0;
        for(int i=0;i<lenStr;i+=2)
        {
            if(str[i]-32 != str[i+1])
            {
               if(ara[str[i+1]-64] >0)
                {
                    ara[str[i+1]-64]--;
                    ara[str[i]-96]++;
                    //printf("aise %d\n",i);
                }
            else
            {
                neededKeys++;
                ara[str[i]-96]++;
            }
            }
        }
        printf("%d\n",neededKeys);
    }
    return 0;
}
