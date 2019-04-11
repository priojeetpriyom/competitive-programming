#include <stdio.h>
#include <cstring>
#include <climits>
int main()
{
    int t,n;
    long long a,b;
    long long max_input,max_val,total_number;
    int lowest_val;
    int z=1;
    long long ara[1010];
    scanf("%d",&t);
    //printf("max%d\n",INT_MAX);
    while(t--)
    {
        scanf("%d",&n);
        max_input=-1,max_val=-1,total_number=0,lowest_val=1000000000;//INT_MAX;
        for(int i=1;i<1005;i++)
            ara[i]=0;
          //printf("\nten %d\n",ara[10]);
        while(n--)
        {
            scanf("%lld %lld",&a,&b);

            if(ara[b]!=0) ara[b]+=a;
            else ara[b] = a;
            if(b>max_input) max_input=b;
        }
        long long sum=0;
        //
        for(int i= max_input;i>=0;i--)
            {

                if(ara[i]!=0)
                {
                   // printf("i %d %d",i);
                    total_number+=ara[i];
                    //printf("i %d total %d\n",i,total_number);
                    if(i<lowest_val)  lowest_val=i;

                     sum=lowest_val*total_number;
                    //printf("%d %d\n",sum,max_val);
                    if(sum>max_val)
                        {
                            max_val=sum;
                            //sum=0;
                        }
                }
            }
        printf("Case %d: %lld\n",z++,max_val);
    }
    return 0;
}
