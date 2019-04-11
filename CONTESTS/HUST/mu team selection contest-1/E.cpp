#include <bits/stdc++.h>
#define MXLEN 100000000
using namespace std;
int primes[MXLEN];
bool isPrime[MXLEN];
int lenPrimes=0;
bool primeCheck(long long n)
{
    if(n<2)
        return false;
    if(n<4)
        return true;
    if(n%2==0)
        return false;
    int root= sqrt(n)+2;
    for(int i=2; i<root; i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
//void primeGeneration()
//{
//    isPrime[0]=0;
//    isPrime[1]=0;
//    int root= sqrt(MXLEN)+2;
//    for(int i=2; i<MXLEN; i++)
//        isPrime[i]=true;
//    for(int i=2; i<root; i++)
//    {
//        if(isPrime[i]==true)
//        {
//            primes[lenPrimes++]=i;
//            for(int x=i*i; x<MXLEN; x+=i)
//                isPrime[x]=false;
//
//        }
//    }
////        for(int i=0;i<101;i++)
////    printf("%d ",primes[i]);
////    printf("\n");
//    //printf("bool2 %d\n",isPrime[2]);
//}
long long numOfDivs(long long n)
{

    if(n==6)
        return 6;
    long long divisors=1;
    int root= sqrt(n)+2;
    //printf("root %d\n",root);
    if(primeCheck(n))
        return 1;
    for(int j=2; j<root; j++)
    {
        if(n%j==0)
        {
            if(n/j!=j)
            {
                divisors+=n/j;
            }
            divisors+=j;

        }
    }
    return divisors;
}
long long power(int n,int times)
{
    long long result=1;
    for(int i=0; i<times; i++)
        result*=n;
    return result;
}
int main()
{
    freopen("myOutput.txt","w",stdout);
    long long n;
    //primeGeneration();
    //printf("oka\n");
    //while(scanf("%I64d",&n)==1)
    for(int n=1; n<32; n++)
    {

        //{

        long long perfectNumber=power(2,n-1);
        //printf("perfect number %I64d\n",perfectNumber);
        long long temp=perfectNumber;
        perfectNumber*=(perfectNumber*2-1);
        //printf("perfect number %I64d\n",perfectNumber);
        long long divisors= numOfDivs(perfectNumber);
        //printf("divisors %I64d perfect number %I64d\n",divisors,perfectNumber);
//            divisors=(divisors*divisors)+divisors;
//            divisors/=2;
        printf("%d-> ",n);
        if(divisors==perfectNumber)
            printf("Perfect: %I64d!\n",perfectNumber);
        else if(primeCheck(n))
            printf("Given number is prime. But, NO perfect number is available.\n");
        //}
        else
            printf("Given number is NOT prime! NO perfect number is available.\n");
    }
    return 0;
}
