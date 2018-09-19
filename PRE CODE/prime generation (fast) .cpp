#include <bits/stdc++.h>
//#define longlong long long

using namespace std;


bool is_prime(long long n)
{
    if(n<2)
        return false;
    else if(n<4)
        return true;
    else if(n%2==0)
        return false;
    long long root= sqrt(n)+2;
    for(long long i=3; i<root; i+=2)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
bool prime_gen[100000000];
int primes[6000000];
int len_primes=1;
int main()
{
//    //int len_prime=1;
//    //freopen("myInput.txt","r",stdin);
//
//    for(int i=3; i<100000000; i+=2)
//    {
//        prime_gen[i]=true;
//    }
////    prime_gen[0]=false;
////    prime_gen[1]=false;
//    prime_gen[2]=true;
//    primes[len_primes++]=2;
////    primes[len_prime++]=1;
//    //primes[len_prime++]=2;
//    int x=4;
//    while(x<100000000)
//    {
//        prime_gen[x]=false;
//        x+=2;
//    }
//    for(int i=3; i<10000; i+=2)
//    {
//        if(prime_gen[i]== true)
//        {
//            //printf("%d ",i);
//            primes[len_primes++]=i;
//            x=i+i;
//            while(x<100000000)
//            {
//                prime_gen[x]=false;
//                x+=i;
//            }
//        }
//    }
//    for(int i=10001;i<100000000;i+=2)
//        if(prime_gen[i])
//            primes[len_primes++]=i;
char str[100] [100];
for(int i=0;i<8;i++)
{
        if(scanf("%s",str[i])==EOF)
            break;
}
     return 0;
}

