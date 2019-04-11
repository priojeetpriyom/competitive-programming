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
    if(n==2) return true;
    for(int i=2; i<root; i++)
        if(n%i==0)
            return false;
    return true;
}
//int ara[10000003];
bool flag [1000003];

int main ()
{


    int n=1000000,root;
    //scanf("%d",&n);
    root= sqrt(n)+2;
    n++;
    for(int i=2; i<n; i++) flag[i] = true;
    for(int i=2; i<root; i++)
    {
        if(flag[i] != false && is_prime(i,sqrt(i)+2)==true)
        {
            //int j=2;

            int x=i+i;
            //printf("i %d x %d\n",i,x);
            while(x<n)
            {
                //  printf("x %d\n",x);
                flag[x] = false;
                x+=i;
                //x=ara[i]*j;
            }
        }
    }
    while(1)
    {
        scanf("%d",&n);
        if(n==0) break;
        //n--;


        for(int i=2; i<n; i++)
            if(flag[i]== true && flag[n-i]== true)
            {
                if(i>n-i) {
                    printf("%d = %d + %d\n",n,n-i,i);
                }
                else {

                    printf("%d = %d + %d\n",n,i,n-i);
                }
                flag[0]=false;
                break;
            }
        if(flag[0]==true)
            printf("Goldbach's conjecture is wrong.\n");
        flag[0]=true;
    }


    return 0;
}

