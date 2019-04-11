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

    int l=0;
    int j=2;
    for(i=3; i<root; i+=2)
    {
        if(flag[i]== true && is_prime(i,sqrt(i)+2)== true)
        {
            if(i-j==2)
            {
                ara[l++]=j;
                ara[l++]=i;
            }
            j=i;
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
        {
            if(i-j==2)
            {
                ara[l++]=j;
                ara[l++]=i;
            }
            j=i;
        }
    }

    while(scanf("%d",&n)==1)
    {
        n+=n-2;
        printf("(%d, %d)\n",ara[n],ara[n+1]);
    }
    return 0;
}
