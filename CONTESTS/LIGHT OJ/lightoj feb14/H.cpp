#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n)
{
    int root= sqrt(n)+2;
    if(n!=2 && n%2==0 || n==1)
        return false;
    for(int i=3; i<root; i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
int main()
{
    bool prime_gen[1011];
    int primes[1011],len_mx;
    int len_prime=1,cnt_power,mx;

    for(int i=0; i<1011; i++)
    {
        primes[i]=INT_MAX;
        prime_gen[i]=true;
        // powers[i]=0;
    }
    primes[len_prime++]=1;
    primes[len_prime++]=2;
    for(int i=3; i<1011; i+=2)
    {
        if(isPrime(i)==true)
        {
            primes[len_prime++]=i;
            int x=i+i;
            while(x<1011)
            {
                prime_gen[x]=false;
                x+=i;
            }
        }
    }
    len_mx=len_prime-1;

    long long n;
    long long root;
    int tCase;
    int i;
    scanf("%d", &tCase);
    while(tCase--) {
        long long mx=0,mxI=0;
        scanf("%lld", &n);
        root = sqrt(n);
        if(isPrime(n))
            printf("%lld\n",n-1);
        else {
            i=len_mx-1;
            while(i>1) {
            if(n%primes[i]==0)
            {
                root= primes[i];
                break;
//                if(mx )
            }
            }
//            while(n% (primes[i] *root) ==0 && root* primes[i] <n)
//                root*=primes[i];
            printf("%lld\n", abs(n/root - root));
        }
        }
    return 0;
}
