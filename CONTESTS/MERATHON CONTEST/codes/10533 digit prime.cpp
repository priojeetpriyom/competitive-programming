#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

bool is_prime(int n,int root)
{
    for(int i=3; i<root; i+=2)
        if(n%i==0)
            return false;
    return true;
}
int main ()
{
    int n=100,ara[80003];
    bool flag[1000003];
    bool flag2[80003];
    n++;
    flag[0]=false;
    flag[1]=false;

    for(int i=3; i<n; i+=2)
        flag[i] = true;
    flag[2]=true;
    for(int i=4; i<n; i+=2)
        flag[i] = false;
    n--;
    int root= sqrt(n) +2;
    n++;
    ara[0]=2;
    int len=1;
    int len_flag2=0;
    for(int i=3; i<root; i+=2)
    {
        if(flag[i]== true && is_prime(i,sqrt(i)+2)== true)
        {

            ara[len++]=i;
            int temp=i;
            int sum=0;
            while(temp>0)
            {
                sum+=temp%10;
                temp/=10;
            }
            //printf("i %d sum %d\n",i,sum);
            if(flag[sum]==true)
                flag2[len_flag2++]=true;
            else flag2[len_flag2++]=false;

            int multiple=i+i;
            while(multiple<n)
            {
                flag[multiple] = false;
                multiple+=i;
            }
        }
    }
    root-=2;
    if(root%2==0) root++;
    printf("root %d\n",root);
    for(int i=root; i<n; i+=2)
    {
        if(flag[i]==true)
        {
            ara[len++]=i;
            //flag2[len_flag2++]=true;
        }
        int temp=i;
        int sum=0;
        while(temp>0)
        {
            sum+=temp%10;
            temp/=10;
        }
        if(i==31) printf("sum %d\n",sum);
        if(i==31 && flag[sum]==true)
            flag2[len_flag2++]=true;
        else flag2[len_flag2++]=false;
    }
    for(int i=0; i<len; i++)
    {
        printf("%d %d\n",ara[i],flag2[i]);
    }

    scanf("%d",&n);

    while(n--)
    {
        int start,endd;
        scanf("%d %d",&start,&endd);
        endd++;
        int ct=0, temp,i=0;

        while(ara[i]<start) i++;
        for(; ara[i]<endd; i++)
        {
            if(flag2[i]==true) ct++;
        }
        printf("%d\n",ct);
    }

    return 0;
}
