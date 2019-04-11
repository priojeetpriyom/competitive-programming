#include <bits/stdc++.h>

using namespace std;
//int b_search(int ara[],int item,int high,int low,int mid)
//{
//    while(high>low)
//    {
//        if(ara[mid]== item)
//        {
//            return mid;
//        }
//        else if(ara[mid]>item)
//            high=mid-1;
//        else low=mid+1;
//        mid=(high+low)/2;
//    }
//    if(ara[mid]>item)
//        while(ara[mid]>item)
//            mid--;
//    else
//        while(ara[mid+1]<item)
//            mid++;
//    return mid;
//}
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
    int primes[1011],n,len_mx;
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
    int num;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&num);
        int cnt=0;
        if(isPrime(num))
        {
            printf("I have no valentine.\n");
            continue;
        }

        else
        {
            for(int i=2; num>1; i++)
            {
                if(num%primes[i]==0)
                {
                    while(num%primes[i]==0)
                    {

                        num/= primes[i];

                        //printf("num %d prime %d\n",num,primes[i]);
                    }
                    cnt++;
                    if(isPrime(num)) {
                        cnt++;
                        break;
                    }

                }
            }
            if(cnt==0)
                printf("I have no valentine.\n");
            else
                printf("I have %d gf , Let's enjoy it.\n", cnt);
        }


    }
    return 0;
}
