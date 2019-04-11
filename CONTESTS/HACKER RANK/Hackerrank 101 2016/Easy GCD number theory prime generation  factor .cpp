#include <bits/stdc++.h>

using namespace std;
int sieveAra[3125];
int primes[10000],lenPrime=0;
void sieve()
{
    for(int i=3; i<320; i+=2)
    {
        if(((sieveAra[i/32]>>(i&31)) &1) == 0)
        {
//                printf("%d\n",i);
            for(int j= i*i; j<100000; j+=i)
            {
                sieveAra[j/32]= (sieveAra[j/32] | (1<<(j&31)));
            }
        }
    }
//    int cnt=1;
    primes[lenPrime++] = 2;
    for(int i=3; i<100000; i+=2)
        if(((sieveAra[i/32]>>(i&31)) &1)==0)
        {
            primes[lenPrime++] = i;
        }
}

int divs[1000], lenDivs=0;


void findDivisors(int num)
{
    lenDivs=0;
    int root = sqrt(num)+1;
    for(int i=0; primes[i]<root; i++)
    {
        if(num%primes[i]==0)
        {
//            printf("primes %d\n",primes[i]);
//            divsFreq[i]++;
            num/=primes[i];
            divs[lenDivs++] =primes[i];
//            divs[lenDivs++] =num;
            while(num%primes[i]==0)
            {
                num/=primes[i];
//                divs[lenDivs++]=num;
            }
            if(num==1)
                break;
        }
    }
    if(num>1)
        divs[lenDivs++] = num;
}
int ara[100001];
int main ()
{
//    cout<< (1<<5)<<endl;
    sieve();

    int n,k;
    while(scanf("%d %d",&n,&k)==2)
    {
//        for(int i=0; i<10000; i++)
//            divsFreq[i]=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&ara[i]);

        }
        findDivisors(ara[0]);
         int ansDiv= k+2;
//         printf("lendiv %d div %d\n",lenDivs,divs[0]);
        for(int j=0; j<lenDivs; j++)
        {
            bool del=false;
             for(int i=1; i<n; i++) {
                if(ara[i]%divs[j] !=0) {
                    del=true;
                    break;
                }
            }
            if(!del)
            {
                ansDiv=divs[j];
                break;
            }

        }
        if(lenDivs==0) {
            if(n==1) {
                ansDiv=ara[0];
            }
            else
                ansDiv = k+2;
        }
        printf("%d\n", (k/ansDiv)*ansDiv);

    }
}



