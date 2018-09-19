#include <bits/stdc++.h>

using namespace std;
int b_search(int ara[],int item,int high,int low,int mid)
{
    while(high>low)
    {
        // printf("high %d low %d mid %d\n",high,low,mid);
        if(ara[mid]== item)
        {
            return mid;
            //printf("Fs\n");
        }
        else if(ara[mid]>item)
            high=mid-1;
        else low=mid+1;
        mid=(high+low)/2;
    }
    if(ara[mid]== item)
    {
        return mid;
        //printf("Fs\n");
    }
    if(ara[mid]>item)
        while(ara[mid-1]>item)
            mid--;
    else

        while(ara[mid]<item)
            mid++;
    //  printf("%d mid\n",mid);
    return mid;
}
bool is_prime(int n)
{
    if(n==2)
        return true;
    if(n==1)
        return false;
    int root= sqrt(n)+2;
    for(int i=2; i<root; i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
int sum_of_digit(int n)
{
    int sum=0;
    while(n>0)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int primes[40000],len_mx;
bool prime_gen[40000];
int main()
{
//    if(is_prime(2))
//        printf("baaler code koro tumi\n");
    int len_prime=1,cnt_power,mx;

    for(int i=0; i<40000; i++)
    {
        primes[i]=INT_MAX;
        prime_gen[i]=true;
        // powers[i]=0;
    }
    primes[0]=-1;
    prime_gen[0]=false;
    prime_gen[1]=false;
    //primes[len_prime++]=1;
    primes[len_prime++]=2;
    len_mx=4;

    while(len_mx<40000)
    {
        prime_gen[len_mx]=false;
        len_mx+=2;
    }
    len_mx=2;
    for(int i=3; i<40000; i+=2)
    {
        if(prime_gen[i]== true && is_prime(i)==true)
        {
            primes[len_prime++]=i;
            int x=i+i;
            while(x<40000)
            {
                prime_gen[x]=false;
                x+=i;
            }
        }
        else prime_gen[i]=false;
    }

    int tcase,n,sum_num=1,sum_primes=0;
    scanf("%d",&tcase);
    while(tcase--)
    {
        scanf("%d",&n);
        if(n<2)
        {
            n=2;
        }
        n++;
        sum_num=1,sum_primes=0;
        while(sum_num!=sum_primes)
        {

            sum_num=sum_of_digit(n);
            int num=n;
            sum_primes=0;
            int i=1;
            len_mx=0;
            if(!is_prime(num))
                while(num>1)
                {
                    while(num%primes[i]==0)
                    {
                        sum_primes+=sum_of_digit(primes[i]);
                        num/=primes[i];
                        if(is_prime(num))
                        {
                            sum_primes+=sum_of_digit(num);
                            len_mx=-1;
                            break;
                        }
                    }
                    i++;
                    if(len_mx== -1)
                        break;
                }

            n++;
//
            //printf("sum prime %d sum num %d\n",sum_primes,sum_num);
        }
        printf("%d\n",n-1);
    }

//    cout<<num<<endl;
    return 0;
}
