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
    if(n<2)
        return false;
    else if(n<4)
        return true;
    int root= sqrt(n)+2;
    for(int i=2; i<root; i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
int main()
{
    bool prime_gen[1010];
    int primes[1010],n,len_mx;
    int len_prime=1,cnt_power,mx;

    for(int i=0; i<1010; i++)
    {
        primes[i]=INT_MAX;
        prime_gen[i]=true;
        // powers[i]=0;
    }
    primes[len_prime++]=1;
    primes[len_prime++]=2;
    for(int i=3; i<1010; i+=2)
    {
        if(prime_gen[i]== true && is_prime(i)==true)
        {
            primes[len_prime++]=i;
            int x=i+i;
            while(x<1010)
            {
                prime_gen[x]=false;
                x+=i;
            }
        }
    }
//    len_mx=len_prime-1;
    int num,cnt;
    bool repeat,prime;
    while(scanf("%d",&num)==1 && num!=0)
    {
        printf("%d : ",num);
        if(is_prime(num))
        {
            printf("1\n");
            continue;
        }
        cnt=0;
        int root= sqrt(num)+2;
//        if(root<4)
//            root++;

        prime=false;
        for(int i=2; primes[i]<root && num>1; i++)
        {
            repeat=false;

            while(num%primes[i]==0)
            {
               // printf("\nnum %d\n",num);
                num/=primes[i];
                if(!repeat)
                {
                    repeat=true;
                    cnt++;

                }

                if(is_prime(num) && num!=primes[i])
                    {
                       // printf("oka");
                        cnt++;
                        prime=true;
                        break;
                    }

            }
            if(prime)
                break;
        }
        printf("%d\n",cnt);
    }
    return 0;
}

