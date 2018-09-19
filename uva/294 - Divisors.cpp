#include <bits/stdc++.h>

using namespace std;
int b_search(int ara[],int item,int high,int low,int mid)
{
    while(high>low)
    {
        if(ara[mid]== item)
        {
            return mid;
        }
        else if(ara[mid]>item)
            high=mid-1;
        else low=mid+1;
        mid=(high+low)/2;
    }
    if(ara[mid]>item)
        while(ara[mid]>item)
            mid--;
    else
        while(ara[mid+1]<item)
            mid++;
    return mid;
}
bool is_prime(int n)
{
    int root= sqrt(n)+2;
    for(int i=3; i<root; i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
int main()
{
    bool prime_gen[40001];
    int primes[40001],n,len_mx;
    int len_prime=1,cnt_power,mx;

    for(int i=0; i<40001; i++)
    {
        primes[i]=INT_MAX;
        prime_gen[i]=true;
       // powers[i]=0;
    }
    primes[len_prime++]=1;
    primes[len_prime++]=2;
    for(int i=3; i<40001; i+=2)
    {
        if(prime_gen[i]== true && is_prime(i)==true)
        {
            primes[len_prime++]=i;
            int x=i+i;
            while(x<40001)
            {
                prime_gen[x]=false;
                x+=i;
            }
        }
    }
    len_mx=len_prime-1;
    int c,pos_lim;
    int tcase,u_bound,l_bound;
    scanf("%d",&tcase);
    while(tcase--)
    {
        scanf("%d %d",&l_bound,&u_bound);
        printf("Between %d and %d, ",l_bound,u_bound);
        u_bound++;
        int divisors,mx_num=0,mx_divisor=0;
        while(l_bound<u_bound)
        {
            int num=l_bound,divisors=1;
//            if(num==3)
//                divisors=2;
            int root=sqrt(num)+2;
            for(int i=2;num>1 && primes[i]<root;i++)
            {
                cnt_power=1;
                while(num%primes[i]==0)
                {
                    cnt_power++;
                    num/=primes[i];
                }
                divisors=divisors*cnt_power;
            }
            //divisors+=2;
            if(divisors>mx_divisor)
            {
                mx_divisor=divisors;
                mx_num=l_bound;
            }
            l_bound++;
        }
        if(mx_divisor==1 && u_bound!=2)
            mx_divisor=2;
        printf("%d has a maximum of %d divisors.\n",mx_num,mx_divisor);
    }
    return 0;
}
