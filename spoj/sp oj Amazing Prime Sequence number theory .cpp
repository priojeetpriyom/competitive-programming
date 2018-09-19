#include <bits/stdc++.h>
using namespace std;
bool notPrime[10000001];
int primes[1601],lenPrimes=0, lenSequence=0;
long long sequence[10000001];
long long findMinDiv(int n)
{
    if(!notPrime[n])
        return n;
    for(int i=0; i<lenPrimes; i++)
        if(n%primes[i]==0)
            return primes[i];
}
int main()
{
//    freopen("myOutput.txt","w",stdout);
    //freopen("myInput.txt",") ;;;we
    int t=0;
//    for(int i=0; i<10000001; i++)
//        if(notPrime[i])
//        t++;
//    cout<<t;
    for(int i=4; i<10000001; i+=2)
        notPrime[i]=true;
    for(int i=3; i<10000001; i+=2)
    {
        if(!notPrime[i])
            for(long long x=(long long) i*i; x<10000001; x+=i)
                notPrime[x]=true;
    }
    for(int i=2; i<3200; i++)
        if(!notPrime[i])
            primes[lenPrimes++]= i;

    sequence[0]= 0;
    sequence[1]= 0;
    sequence[2]= 2;
    for(int i=3; i<10000001; i++)
    {
        sequence[i] = sequence[i-1]+findMinDiv(i);
    }

    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("%lld\n",sequence[n]);
    }
    return 0;
}


