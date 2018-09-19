#include <bits/stdc++.h>
//#include <iostream>
//#include <cstdio>
//#include <string.h>
//#include <math.h>
//#include <algorithm>
//#include <stack>
//#include <queue>
//#include <climits>
//#include <string>
//#include <stdlib.h>
//#define N 1000000

using namespace std;
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
    bool prime_gen[101];
    int primes[101],powers[101],n,len_mx;
    int len_prime=0,cnt_power;

    for(int i=0; i<100; i++)
    {
        primes[i]=0;
        prime_gen[i]=true;
        powers[i]=0;
    }
    primes[len_prime++]=2;
    for(int i=3; i<101; i+=2)
    {
        if(prime_gen[i]== true && is_prime(i)==true)
        {
            primes[len_prime++]=i;
            int x=i+i;
            while(x<101)
            {
                prime_gen[x]=false;
                x+=i;
            }
        }
    }
//    for(int i=0;i<25;i++)
//        printf("%d ",primes[i]);
//    cout<<endl;
    while(scanf("%d",&n)==1 && n!=0)
    {
//        if(n<10)
            printf("%3d! =",n);
//        else
//            printf("%d! =",n);
        len_mx=0;
        for(int i=0; i<100; i++)
            powers[i]=0;
        int len_power=0;
        len_prime=0;
        while(n>1)
        {
            int num=n--;
            len_prime=0;
            while(num>1)
            {

                if(num%primes[len_prime]==0)
                {

                    powers[len_prime]++;

                    if(len_prime>=len_mx)
                        {
                            //if(num==53)
//                        printf("prime %d len %d power %d\n",primes[len_prime],len_prime,powers[len_prime]);
                            len_mx=len_prime+1;

                            //printf("oka\n");
                        }
                    //if(num==53)
                        //printf("len_prime %d\n",len_mx);
                    num/=primes[len_prime];
                }
                else len_prime++;
            }
        }
        int cnt=0;
        for(int i=0;i<len_mx;i++)
            {

                if(cnt<15)
                {
                    cnt++;
                    //if(powers[i]<10)
                    printf("%3d",powers[i]);
//                else
//                    printf(" %d",powers[i]);

                }
                else {
                    cnt=0;
                    printf("\n        %d",powers[i]);
                }

            }
        printf("\n");
//        for(int i=0;i<len_mx;i++)
//            printf("%d ",primes[i]);
    }
    return 0;
}

