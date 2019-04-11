#include <bits/stdc++.h>
using namespace std;
int prime_generate[100010],primes[4000];
int len_primes=0;
int divs[4000];

int get_power(int n, int pw, int div)
{
    int x=1;
    for(int i=0; i<pw; i++)
    {
        x*=n;
    }
    return (x/(div));
}

int get_total_divisors(int n)
{
    memset(divs,0, sizeof(divs));
    int len_divs=0;
    for(int i=0; n>1; i++)
    {
        int cnt=0;
        while(n%primes[i]==0)
        {
            n/=primes[i];
            cnt++;
        }
        divs[len_divs++]=cnt;
    }
    int x=1;
    for(int i=0; i<len_primes; i++)
    {

        if(divs[i]>0)
        {
//            printf("x %d ",divs[i]);
//            x*=get_power(primes[i],divs[i]+1, primes[i]-1);
        }
    }
    printf("\n");
}

void prime_gen()
{
    int root = 100001+2;
    for(int i=3; i<root; i+=2)
    {
        if(!prime_generate[i])
        {
            for(int j= i*i; j<100001; j+=i)
                prime_generate[j]=1;
        }
    }

    primes[len_primes++]=2;
    for(int i=3; i<root; i+=2)
    {
        if(!prime_generate[i])
        {
            if(i<101)
                printf("%d ",i);
            primes[len_primes++] = prime_generate[i];
        }
    }

    printf("\n");
}



int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);
    prime_gen();
    int t,n,ara[1001];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int x, mx_diff=0, mx_num=0,diff;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&x);

            if(!prime_generate[x])
            {
                diff=x-1;
            }
            else diff = get_total_divisors(x);
            printf("div %d\n",diff);
            diff = (diff - (x*2));

            if(diff>0 && diff>mx_diff)
            {
                mx_diff = diff;
                mx_num = x;
            }
            else if(diff>0 && diff == mx_diff && x<mx_num)
                mx_num=x;
        }



        printf("%d %d",mx_num, mx_diff-mx_num);

    }

    return 0;
}
