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
    bool prime_gen[1001];
    int primes[1001],powers[1001],n,len_mx;
    int len_prime=1,cnt_power,mx;

    for(int i=0; i<1000; i++)
    {
        primes[i]=INT_MAX;
        prime_gen[i]=true;
        powers[i]=0;
    }
    primes[len_prime++]=1;
    primes[len_prime++]=2;
    for(int i=3; i<1001; i+=2)
    {
        if(prime_gen[i]== true && is_prime(i)==true)
        {
            primes[len_prime++]=i;
            int x=i+i;
            while(x<1001)
            {
                prime_gen[x]=false;
                x+=i;
            }
        }
    }
    mx=len_prime-1;
    int c,pos_lim;
    while(scanf("%d %d",&n,&c)==2)
    {
        printf("%d %d:",n,c);
        int pos = b_search(primes,n,mx,0,mx/2);
        //printf("pos %d\n",pos);
        pos_lim=pos;

        //*=2;
        int c_new=c;
        if(pos%2==1)
            c_new--;
        pos=(pos+1)/2;
        //printf("c %d\n",c);

            if(pos+c>pos_lim || pos<=c)
            {
                //printf("pos_lim %d\n",pos_lim);
                for(int i=1;i<=pos_lim;i++)
                    printf(" %d",primes[i]);
            }
            else
            {
                //c+=pos;
                for(int i=pos-c+1;i<=pos+c_new;i++)
                {
                    printf(" %d",primes[i]);
                }
            }
            printf("\n\n");
    }
    return 0;
}

