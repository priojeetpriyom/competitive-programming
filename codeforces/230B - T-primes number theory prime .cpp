#include <bits/stdc++.h>
using namespace std;
long long ara[100001], primes[1000010];
bool isTprime[100001],isPrime[1000011];
//bool isPrime(long long n)
//{
//    if(n<2 )
//        return false;
//    else if(n<4)
//        return true;
//    else if(n%2==0)
//        return false;
//    else
//    {
//        int root = sqrt(n)+2;
//        for(int i=3; i<root; i+=2)
//            if(n%i == 0)
//                return false;
//    }
//    return true;
//
//
//}
int main()
{
    int n;
    isPrime[0]= isPrime[1]=false;
    //isPrime[2]=true;
    //isPrime[3]=true;
    primes[0]= primes[1]= -1;
    primes[2]=4;
    for(int i=3; i<1000001;i+=2)
        isPrime[i]=true;
    //printf("oka");
    for(long long i=3; i<1000001;i+=2)
    {
        if(isPrime[i])
        {
            primes[i] = i*i;
            for(long long x= i*i; x<1000001; x+=i)
                isPrime[x]= false;
        }
        else
            primes[i]= 0;
    }

    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%I64d",&ara[i]);
        long long root = sqrt(ara[i]), rootOfroot= sqrt(root);
        long long prev=ara[i];
        //cout<<root<<endl;
        if(primes[root] == ara[i])
            isTprime[i]= true;
        else
             isTprime[i] = false;
    }
    for(int i=0; i<n; i++)
    {
        if(isTprime[i])
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

