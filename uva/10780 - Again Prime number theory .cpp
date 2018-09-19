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
    bool prime_gen[100];
    int primes[100],len_mx;
    int len_prime=1,cnt_power,mx;

    for(int i=0; i<100; i++)
    {
        primes[i]=INT_MAX;
        prime_gen[i]=true;
        // powers[i]=0;
    }
    primes[len_prime++]=1;
    primes[len_prime++]=2;
    for(int i=3; i<100; i+=2)
    {
        if(prime_gen[i]== true && is_prime(i)==true)
        {
            primes[len_prime++]=i;
            int x=i+i;
            while(x<100)
            {
                prime_gen[x]=false;
                x+=i;
            }
        }
    }
    int m,n,tCase;
    scanf("%d",&tCase);
    tCase++;
    for(int i=1; i<tCase; i++)
    {
        scanf("%d %d",&m,&n);
        printf("Case %d:\n",i);
        int mn_div=INT_MAX,mn=INT_MAX;
        int lenDiv=0;
        bool prime=false;
        if(is_prime(m))
        {
            int temp=n;
            int cnt_pow=0;
            while(temp>1)
            {
                temp/=m;
                cnt_pow+=temp;
            }
            //cnt_pow/=m;
            if(cnt_pow<mn)
                mn=cnt_pow;
        }
        else
        {
//            for(int j=0; j<100; j++)
//                div[j]=0;
            for(int j=2; m>1; j++)
            {
                int cnt_div=0;
                //printf("cnt %d\n",cnt_div);
                while(m%primes[j]==0)
                {
                    m/=primes[j];
                    cnt_div++;
                }
                if(cnt_div!=0)
                {
                    int temp=n;
                    int cnt_pow=0;
                    while(temp>1)
                    {
                        temp/=primes[j];
                        cnt_pow+=temp;
                    }
                    cnt_pow/=cnt_div;
                    if(cnt_pow<mn)
                        mn=cnt_pow;
                }
                if(is_prime(m))
                {
                    int temp=n;
                    int cnt_pow=0;
                    while(temp>1)
                    {
                        temp/=m;
                        cnt_pow+=temp;
                    }
                    //cnt_pow/=m;
                    if(cnt_pow<mn)
                        mn=cnt_pow;
                    break;
                }
            }

        }
        if(mn>0)
        printf("%d\n",mn);
        else
            printf("Impossible to divide\n");
    }

    return 0;
}
