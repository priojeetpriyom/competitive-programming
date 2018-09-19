#include <bits/stdc++.h>

using namespace std;

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
bool prime_gen[100000];
int primes[6000000],len_mx;
int main()
{
//    if(is_prime(4))
//        cout<<"4 o prime"<<endl;
    int len_prime=1;

    for(int i=4; i<100000; i+=2)
    {
        //primes[i]=INT_MAX;
        prime_gen[i]=false;
        // powers[i]=0;
    }
    for(int i=3; i<100000; i+=2)
    {
        //primes[i]=INT_MAX;
        prime_gen[i]=true;
        // powers[i]=0;
    }
    prime_gen[0]=false;
    prime_gen[1]=false;
    prime_gen[2]=true;
//    primes[len_prime++]=1;
    primes[len_prime++]=2;
    for(int i=3; i<100000; i+=2)
    {
        if(prime_gen[i]== true && is_prime(i)==true)
        {
            primes[len_prime++]=i;
            int x=i+i;
            while(x<100000)
            {
                prime_gen[x]=false;
                x+=i;
            }
        }

    }

    int n;
    while(scanf("%d",&n)==1 && n!=0)
    {
        int relativePrimes=n-1;
        if(is_prime(n))
        {
            printf("%d\n",relativePrimes);
            continue;
        }
        int divisors[1000],lenDiv=0;
        int num=n;
        bool prime=false;
        for(int i=1;n>1;i++)
        {
            while(n%primes[i]==0)
            {
                //printf("%d ",primes[i]);
                n/=primes[i];
                if(lenDiv==0)
                    divisors[lenDiv++]=primes[i];
                else if(primes[i]!=divisors[lenDiv-1])
                    divisors[lenDiv++]=primes[i];
                if(is_prime(n) && n!= divisors[lenDiv-1])
                {
                   // printf("%d ",n);
                    prime=true;
                    divisors[lenDiv++]=n;
                    break;
                }
            }
            if(prime)
                break;
        }
        n=num-1;
        //printf("\n",lenDiv);
        //printf("oka %d\n",lenDiv);
        for(int i=0;i<lenDiv;i++)
        {
//            for(int j=i+1;j<lenDiv;j++)
//            {
//                if(divisors[i]*divisors[j]<num)
//                    relativePrimes++;
//            }
            relativePrimes=relativePrimes-(relativePrimes/divisors[i]);
        }
        printf("%d\n",relativePrimes);
        //for(int i=0;i<lenDiv)
    }

    return 0;
}
