#include <bits/stdc++.h>
using namespace std;

int ara[1000100];
bool flag[1000100];
bool is_prime(int n,int root)
{

    if(flag[n]==false)
        return false;
    int i;
    for( i=3; i<root; i+=2)
        if(n%i==0)
            return false;
    return true;
}
bool digitPrime(int n)
{
    //printf("num %d ",n);
    if(n<10)
        return true;
    int sum=0;
    while(n>0)
    {
        sum+=n%10;
        n/=10;
    }

    if(is_prime(sum,sqrt(sum)+2))
        {
            //printf("sum %d\n",sum);
            return true;
        }
        //else cout<<endl;
    return false;
}

int main ()
{
    int n=1000000;
//    int i;
    n++;
    flag[0]=false;
    flag[1]=false;
    flag[2]=true;
    for(int i=0; i<3; i++)
        ara[i]=0;
    for(int i=3; i<n; i+=2)
    {
        flag[i] = true;
        ara[i]=0;
    }
    for(int i=4; i<n; i+=2)
    {
        flag[i] = false;
        ara[i] = 0;
    }
    //n--;
    //int root= sqrt(n) +2;
    //n++;
    ara[2]=1;
    int l=1;
    for(int i=3; i<n; i+=2)
    {
        if(flag[i]== true && is_prime(i,sqrt(i)+2)== true)
        {
            if(digitPrime(i))
                {
                    ara[i]=1;
                    //printf("%d\n",i);
                }
            int multiple=i+i;
            while(multiple<n)
            {
                flag[multiple] = false;
                multiple+=i;
            }
        }
    }
    for(int i=1;i<n;i++)
        //if(ara[i]!=0)
            ara[i]+=ara[i-1];
    int tCase;
    scanf("%d",&tCase);
    while(tCase--)
    {
        int start,endd;
        scanf("%d %d",&start,&endd);

        //printf("%d %d\n",ara[endd],ara[start]);
        if(start==endd && digitPrime(start) && is_prime(start,sqrt(start)+2))
            printf("1\n");
        else
            {
                start--;
                printf("%d\n",ara[endd]-ara[start]);
            }
    }
    return 0;
}

