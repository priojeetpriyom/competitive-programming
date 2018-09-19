#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n,int root)
{
    int i;
    for( i=3; i<root; i+=2)
        if(n%i==0)
            return false;
    return true;
}
int ara[1300000];
bool flag[20000003];
int main ()
{
    int n=20000000;
    int i;
    n++;
    flag[0]=false;
    flag[1]=false;
    for(i=3; i<n; i+=2)
        flag[i] = true;
    flag[2]=true;

    for(i=4; i<n; i+=2)
        flag[i] = false;
    n--;
    int root= sqrt(n) +2;
    n++;
    ara[0]=2;
    int l=1;
    for(i=3; i<root; i+=2)
    {
        if(flag[i]== true && is_prime(i,sqrt(i)+2)== true)
        {
            ara[l++]=i;
            int multiple=i+i;
            while(multiple<n)
            {
                flag[multiple] = false;
                multiple+=i;
            }
        }
    }
    if(root%2==0) root++;
    for(i=root; i<20000000; i+=2)
    {
        if(flag[i] == true)
            ara[l++]=i;
    }
    scanf("%d",&n);
    while(n--)
    {
        int start,endd,ct=0;
        scanf("%d %d",start,endd);
        endd++;
        for(int i=0;ara[i]<endd;i++)
        {
            int temp=ara[i],sum=0;
            while(temp>0)
            {
                sum+=temp%10;
                temp/=10;
            }
            if(flag[sum]==true)
                ct++;
        }
        printf("%d\n",ct);
    }
    return 0;
}
