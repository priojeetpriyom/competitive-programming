#include <bits/stdc++.h>
#define MXLEN 3030
using namespace std;
int primes[MXLEN];
bool isPrime[MXLEN];
int lenPrimes=0;
void primeGeneration()
{
    isPrime[0]=0;
    isPrime[1]=0;
    for(int i=2;i<MXLEN;i++)
        isPrime[i]=true;
    for(int i=2;i<MXLEN;i++)
    {
        if(isPrime[i])
        {
            primes[lenPrimes++]=i;
            for(int x=i*i;x<MXLEN;x+=i)
                isPrime[x]=false;

        }
    }
//    for(int i=0;i<101;i++)
//    printf("%d ",primes[i]);
//    printf("\n");
}
int primeDivisors(int n)
{
    int divisors=0;
    if(isPrime[n]==true)
    {
        return 1;
    }
    else
    {
        for(int j=0;n>1;j++)
            {
                if(n%primes[j]==0)
                {
                    while(n%primes[j]==0)
                        {
                            n/=primes[j];
                            //divisors[i]++;
                        }
                    divisors++;
                    if(isPrime[n])
                    {
                        divisors++;
                        n=1;
                    }
                }
            }

    }
    return divisors;
}
int main()
{
    primeGeneration();
    int almostPrimes[3030],n;
    almostPrimes[0]=0;
    for(int i=1;i<3001;i++)
    {
        if(primeDivisors(i)==2)
        {
            almostPrimes[i]=almostPrimes[i-1]+1;
        }
        else
            almostPrimes[i]=almostPrimes[i-1];
    }
    while(scanf("%d",&n)==1)
        printf("%d\n",almostPrimes[n]);
    return 0;
}
