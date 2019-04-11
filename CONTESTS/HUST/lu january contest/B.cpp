#include <bits/stdc++.h>
#define MXLEN 10000000
using namespace std;
//int primes[MXLEN];
//bool isPrime[MXLEN];
//int lenPrimes=0;
//void primeGeneration()
//{
//    isPrime[0]=0;
//    isPrime[1]=0;
//    for(int i=2; i<MXLEN; i++)
//        isPrime[i]=true;
//    for(int i=2; i<MXLEN; i++)
//    {
//        if(isPrime[i])
//        {
//            primes[lenPrimes++]=i;
//            for(int x=i*i; x<MXLEN; x+=i)
//                isPrime[x]=false;
//
//        }
//    }
//}
int main()
{
//    primeGeneration();
    int n,divs=0,triangleNumbers[100000]={0};
    for(int i=1;i<440;i++)
        if(i%2==0)
            triangleNumbers[((i*i)+i)/2]=1;
    for(int i=1;i< 100;i++)
        printf("%d %d\n",i,triangleNumbers[i]);
    while(scanf("%d",&n)==1)
    {
        int root=sqrt(n);
        int square= root*root;
        //while(root)
    }
    return 0;
}
