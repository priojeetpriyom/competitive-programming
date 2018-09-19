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
    int root= sqrt(n)+2;
    for(int i=3; i<root; i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
int primes[1000011],len_mx,diff[200];
bool prime_gen[1000011];
int main()
{
    int len_prime=1,cnt_power,mx;

    for(int i=0; i<1000011; i++)
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

    while(len_mx<1000011)
        {
            prime_gen[len_mx]=false;
            len_mx+=2;
        }
    len_mx=2;
    for(int i=3; i<1000011; i+=2)
    {
        if(prime_gen[i]== true && is_prime(i)==true)
        {
            primes[len_prime++]=i;
            int x=i+i;
            while(x<1000011)
            {
                prime_gen[x]=false;
                x+=i;
            }
        }
        else prime_gen[i]=false;
    }

    int tcase,u_bound,l_bound;
    scanf("%d",&tcase);
    bool no_champ;
    int mx_dif,mx_num;
    while(tcase--)
    {
        for(int i=0;i<200;i++)
            diff[i]=0;
        scanf("%d %d",&l_bound,&u_bound);
        no_champ=true;
        mx_dif=0;
        l_bound= b_search(primes,l_bound,l_bound,1,(l_bound+1)/2);
      //  printf("lower bound %d\n",primes[l_bound]);
        for(int i=l_bound+1;primes[i]<=u_bound;i++)
        {
            //printf("primes %d %d\n",primes[i-1],primes[i]);
            int dif= primes[i]-primes[i-1];
            if(dif==primes[i])
            {
                no_champ=true;
                break;
            }
            diff[dif]++;
            if(diff[dif]>mx_dif)
            {
                mx_dif=diff[dif];
                mx_num=dif;
                no_champ=false;
            }
            else if(mx_dif==diff[dif])
                no_champ=true;
        }
        if(no_champ)
            printf("No jumping champion\n");
        else
            printf("The jumping champion is %d\n",mx_num);
        //printf("%d\n",diff[4]);
    }

//    cout<<num<<endl;
    return 0;
}

