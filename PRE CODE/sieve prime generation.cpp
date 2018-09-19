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
    for(int i=3;i<root;i+=2)
        if(n%i==0)
            return false;
    return true;
}
int main ()
{
    int n=100;
    bool flag[1000003];
    n++;
    flag[0]=false;
    flag[1]=false;
    for(int i=3;i<n;i+=2)
        flag[i] = true;
    flag[2]=true;
    for(int i=4;i<n;i+=2)
        flag[i] = false;
    n--;
    int root= sqrt(n) +2;
    n++;
    for(int i=3;i<root;i+=2)
    {
        if(flag[i]== true && is_prime(i,sqrt(i)+2)== true)
        {
            int multiple=i+i;
            while(multiple<n)
            {
                flag[multiple] = false;
                multiple+=i;
            }
        }
    }
    for(int i=2;i<n;i++)
        if(flag[i]==1)
            printf("%d ",i);

    return 0;
}
