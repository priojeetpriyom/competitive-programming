#include <bits/stdc++.h>

using namespace std;

int logof(long long n,int div)
{
    int pow=0;
    while(n>=div)
    {
        n/=div;
        pow++;
    }
    return pow;
}
bool is_prime(int n)
{
    if(n<2)
        return false;
    else if(n<4)
        return true;
    else if(n%2==0)
        return false;
    int root= sqrt(n)+2;
    for(int i=3; i<root; i+=2)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
bool prime_gen[1000111];
long long primes[100011];
int len_primes=1;
int main()
{
    //int len_prime=1;
    for(int i=3; i<1000111; i+=2)
    {
        prime_gen[i]=true;
    }
//    prime_gen[0]=false;
//    prime_gen[1]=false;
    prime_gen[2]=true;
//    primes[len_prime++]=1;
    //primes[len_prime++]=2;
    for(int i=2; i<1000111; i++)
    {
        if(prime_gen[i]== true)
        {
            primes[len_primes++]=i;
            int x=i+i;
            while(x<1000111)
            {
                prime_gen[x]=false;
                x+=i;
            }
        }


    }
    //int len_prime=1;
//    for(int i=3; i<1000111; i+=2)
//    {
//        if(!is_prime(i) && almostPrime(i))
//        {
//            almostPrimes[len_mx++]=i;
//        }
//    }
    int tCase;
    scanf("%d",&tCase);
    while(tCase--)
    {
        long long start,endd;
        scanf("%lld %lld",&start,&endd);
        long long lim=endd+1;
        int almostPrimes=0;
        start--;
        for(int i=1;primes[i]*primes[i]<lim;i++)
        {

            int low=0,high=0;

            low =logof(start,primes[i]);
            high=logof(endd,primes[i]);
            if(start<primes[i])
                high--;
            almostPrimes+=high-low;
            //printf("i %d prime %d high %d low %d\n",i,primes[i],high,low);
        }
        printf("%d\n",almostPrimes);
    }
    return 0;
}

