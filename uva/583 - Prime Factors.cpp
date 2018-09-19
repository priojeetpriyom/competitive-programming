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
    bool prime_gen[50001];
    int primes[50001],n,len_mx;
    int len_prime=1,cnt_power,mx;

    for(int i=0; i<50001; i++)
    {
        primes[i]=INT_MAX;
        prime_gen[i]=true;
       // powers[i]=0;
    }
    primes[len_prime++]=1;
    primes[len_prime++]=2;
    for(int i=3; i<50001; i+=2)
    {
        if(prime_gen[i]== true && is_prime(i)==true)
        {
            primes[len_prime++]=i;
            int x=i+i;
            while(x<50001)
            {
                prime_gen[x]=false;
                x+=i;
            }
        }
    }
    len_mx=len_prime-1;
    int num;
    while(scanf("%d",&num)==1 && num!=0)
    {
        bool minus=false;
        if(num== -1)
        {
            printf("-1 = -1\n");
            continue;
        }
        else if(num==1)
        {
            printf("1 = 1\n");
            continue;
        }
        if(num<0)
            {
                printf("%d = -1 x ",num);
                num = abs(num);
                minus=true;
            }
        else
            printf("%d = ",num);
        bool first = true,printed=false;
        int root= sqrt(num)+2;
        //printf("num %d\n",num);
        for(int i=2;primes[i]<root && num>1;i++)
        {
            while(num%primes[i]==0)
            {
                printed=true;
                if(first)
                    {

                        printf("%d",primes[i]);
                        first=false;
                    }
                else
                    printf(" x %d",primes[i]);
                num=num/primes[i];
                //printf("num %d prime %d\n",num,primes[i]);
            }
        }
        if(num>1)
        {
            if(printed)
                printf(" x %d",num);
            else
                printf("%d",num);
        }
        printf("\n");
    }
    return 0;
}
