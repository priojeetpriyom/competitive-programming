#include <stdio.h>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;
int main()
{
    long long t,n,k=0,flag;
    long long ara[1000];
    long long sum;
    scanf("%lld",&t);
    while(k<t)
    {
        sum=1;
        scanf("%d",&n);
        flag=0;
        for(int i=0;i<n;i++)
            scanf("%lld",&ara[i]);
        //printf("oka");
        sort(ara,ara+n);
        long long i=0;
        //printf("%d\n",ara[0]);
        int zero=0;
        for(;i<n;)
        {

            if(ara[i]>0) break;
            else zero++;
            if(zero>1) {
                flag=-1;
                break;
            }
            i++;
        }
        //i--;
        //printf("ara %d\n",ara[i]);
        if(flag!=-1)
        {
            for(long long j=0;i<n;i++,j++)
            {
                sum=sum*(ara[i]-j) %1000000007;
                flag=1;
                //printf("%d %d]\n",i,sum);
                if(ara[i] == 0|| sum<=0)
                {
                    if(ara[i] == 0) zero++;
                    if(zero>1) {
                    flag=-1;
                    break;
                        }
                    flag=-1;
                    break;
                }

            }
        }

        k++;
        if(flag==-1 || flag== 0) printf("Case %d: 0\n",k);
        else
        printf("Case %lld: %lld\n",k,sum);
        flag=0;
    }
    return 0;
}
