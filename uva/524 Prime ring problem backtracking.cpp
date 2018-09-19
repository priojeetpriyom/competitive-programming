#include <bits/stdc++.h>
using namespace std;
bool ara[20],isPrime[35]= {true};
int n;
void primeGenerate()
{
    isPrime[0]=isPrime[1]=false;
    for(int i=2; i<18; i++)
    {
        if(isPrime[i])
        {

            for(int x=i*i; x<35; x+=i)
                isPrime[x]=false;
        }
    }
}
void findPrimeRings(int temp[], int lenTemp ,bool isPicked[])
{
    if(lenTemp==n)
    {
        for(int j=0; j<lenTemp; j++)
            {
                if(j>0)
                    printf(" ");
                printf("%d",temp[j]);
            }
        printf("\n");
        return;
    }
    for(int i =1; i<=n; i++)
    {
//        for(int j=0;j <lenTemp; j++)
//            printf("%d ", temp[j]);
//        printf("\n");
        if(ara[i])
        {
//            if(lenTemp==0)
//            {
////                if(isPrime[i])
////                {
//                    temp[lenTemp] = i;
//                    ara[i]=false;
//                    findPrimeRings(temp,lenTemp+1, isPicked);
//                    ara[i]=true;
//                //}
//            }
//            else
            if(lenTemp==n-1)
            {
                if(isPrime[i+temp[lenTemp-1]] && isPrime[i+temp[0]])
                {
                    temp[lenTemp] = i;
                    ara[i]=false;
                    findPrimeRings(temp,lenTemp+1, isPicked);
                    ara[i]=true;
                }
            }
            else if(isPrime[i+temp[lenTemp-1]])
            {
                temp[lenTemp] = i;
                ara[i]=false;
                findPrimeRings(temp,lenTemp+1, isPicked);
                ara[i]=true;
            }
        }
    }
}
int main()
{
    memset(isPrime, true, sizeof(isPrime));
    primeGenerate();
//    for(int i =1; i<35; i++)
//        printf("%d %d\n",i,isPrime[i]);

    int i=0,temp[20];
    while(scanf("%d",&n)==1)
    {
        if(i>0)
            printf("\n");
        i++;
        printf("Case %d:\n",i);
        memset(ara,true,sizeof(ara));
        ara[1]=false;
        temp[0]=1;
        findPrimeRings(temp, 1, ara);
    }
    return 0;
}

