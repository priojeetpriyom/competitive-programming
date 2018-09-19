#include <bits/stdc++.h>

using namespace std;
int ara[1000001];

bool is_prime(int n)
{
    if(n<2)
        return false;
    else if(n<4)
        return true;
    if(n&1==0)
        return false;
    int root= sqrt(n)+2;
    for(int i=3; i<root; i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
int primes[1000111],len_mx,factors[1000111],f=2;
bool prime_gen[1000111];
int main()
{
    int len_prime=1,cnt_power,mx;

    for(int i=0; i<1000111; i++)
    {
        primes[i]=INT_MAX;
        prime_gen[i]=true;
       // powers[i]=0;
    }
    prime_gen[0]=false;
    prime_gen[1]=false;
    //primes[len_prime++]=1;
    primes[len_prime++]=2;
    len_mx=4;
    factors[1]=0;
    while(len_mx<1000111)
        {
            prime_gen[len_mx]=false;
            len_mx+=2;
        }
    len_mx=2;
    for(int i=3; i<1000111; i+=2)
    {
        if(prime_gen[i]== true && is_prime(i)==true)
        {
            primes[len_prime++]=i;
            int x=i+i;
            while(x<1000111)
            {
                prime_gen[x]=false;
                x+=i;
            }
        }
        else prime_gen[i]=false;
    }

    len_mx=len_prime;
    int n;
    ara[1]=0;
    for(int i=2;i<1000001;i++)
    {
        ara[i]=ara[i-1];
        n=i;
        if(prime_gen[n])
        {
            ara[i]++;
            continue;
        }

        bool prime=false;
        for(int j=1;n>1;j++)
        {
            while(n%primes[j]==0)
            {
                n/=primes[j];
                ara[i]++;
                if(prime_gen[n])
                {
                    ara[i]++;
                    prime=true;
                    break;
                }
            }
            if(prime)
                break;
        }
        //printf("coler %d\n",i);
    }

    while(scanf("%d",&n)==1)
        printf("%d\n",ara[n]);
    return 0;
}
