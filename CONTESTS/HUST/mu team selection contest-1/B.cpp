#include <bits/stdc++.h>
#define MXLEN 1000010
using namespace std;
int primes[MXLEN];
bool isPrime[MXLEN];
int divisors[1000011];
int lenPrimes=0;
void primeGeneration()
{
    isPrime[0]=0;
    isPrime[1]=0;
    for(int i=2;i<MXLEN;i++)
        isPrime[i]=true;
        int root= sqrt(MXLEN)+2;
    for(int i=2;i<root;i++)
    {
        if(isPrime[i]==true)
        {
            primes[lenPrimes++]=i;
            for(int x=i*i;x<MXLEN;x+=i)
                isPrime[x]=false;

        }
    }
    for(int i=0;i<101;i++)
    printf("%d ",primes[i]);
    printf("\n");
    divisors[1]=1;
    divisors[2]=2;
    divisors[3]=2;
    divisors[4]=3;
    divisors[5]=2;
    divisors[6]=4;
    for(int i=7;i<1000001;i++)
    {
        int temp=i;
        if(isPrime[temp])
            divisors[temp]=2;
        else
        {
            divisors[i]=2;
            //bool brek= false;
            root=sqrt(temp)+2;
            for(int j=2;j<root;j++)
            {
                if(temp%j==0)
                {
//                    while(temp%j==0)
//                        {
//                            temp/=primes[j];
//                            divisors[i]++;
//                        }
                    divisors[i]++;
                    if(temp % (temp/j)==0 && j != temp/j)
                    {
                        divisors[i]++;
                        //temp=1;
                    }
                }
            }
        }
    }
    for(int i=1;i<101;i++)
    printf("%d -> %d\n",i,divisors[i]);
    printf("\n");
}
int main()
{
    primeGeneration();
    long long a,b,c;
    long long sum;
    while(scanf("%I64d %I64d %I64d",&a,&b,&c)==3)
    {
        sum=0;
        for(long long i=1;i<=a;i++)
            for(long long j=1;j<=b;j++)
                for(long long k=1;k<=c;k++)
                    {

                        int multiple=i*j*k;
                    printf("%I64d %I64d %I64d multiple %d divisors %d \n",i,j,k,multiple,divisors[multiple]);
                        sum+= divisors[multiple];
                        if(sum>1073741824)
                            sum%=1073741824;
                    }
        printf("%I64d\n",sum);
    }
    return 0;
}
