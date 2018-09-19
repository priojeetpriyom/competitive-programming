#include <bits/stdc++.h>

using namespace std;
int divs[1000005],len=1;
int primeGen[31251];
vector<int> primes;
void sieve()
{
    primeGen[0] = (primeGen[0] | (1<< (0&31)));
    primeGen[0] = (primeGen[0] | (1<< (1&31)));
    for(int i= 2; i<1001; i++)
    {
        if( ((primeGen[(i/32)]>> (i&31)) &1) ==0 )
        {
            primes.push_back(i);
            for(int j= i*i; j<1000001; j+=i)
                primeGen[j/32] = (primeGen[j/32] | (1<< (j&31)));
        }
    }

//    for(int i=0; i<1000; i++)
//        //printf("%d %d\n",i+1,primes[i]);
}

void findDiv()
{
    divs[1]=1;
    divs[0]=0;
    for(int number =2; number< 1000001; number++)
    {
        if(((primeGen[number/32]>>(number&31)) &1) ==0 )
        {
//            if(number==4)
//            printf("baaler code koro tumi\n");
            divs[number] = 2;
            continue;
        }
            int cnt=2, half = sqrt(number)+1, n=number;
        int frequency[100], lenF=0;
        lenF=0;
        for (int i=0; primes[i]<half; i++)
        {   //printf("number %d n %d prime %d\n",number,n,primes[i]);
            //printf("n %d\n",n);
            if(n% primes[i]==0) {
                frequency[lenF]=1;
//                if(number==4)
//                printf("n %d prime %d i %d\n",n, primes[i],i);
                n/=primes[i];
//                if(number==4)
//                printf("n %d prime %d lf %d f %d \n",n, primes[i],lenF, frequency[lenF]);
                while(n%primes[i] ==0)
                {
                    frequency[lenF]++;
                    n/=primes[i];
//                if(number==4)
//                printf("n %d prime %d lf %d f %d \n",n, primes[i],lenF, frequency[lenF]);
                }
                lenF++;
                if(n==1)
                {
                    break;
                }
                if((((primeGen[n/32]>> (n&31)) &1)==0))
                {
                    frequency[lenF] =1;
                    lenF++;
                    break;
                }
            }
            }

//        }
        divs[number] = 1;
        for(int i=0; i<lenF; i++)
        {
            divs[number] *= (frequency[i]+1);
        }
//        if(number ==120) {
//            printf("f %d lenf %d n %d divs %d\n",frequency[lenF],lenF,n, divs[number]);
////        divs[number] +=2;
////        //printf("number %d\n", number);
//    }
//    for(int i=1; i<10; i++)
//        printf("i %d div %d\n",i,divs[i]);
}
}
int main()
{
//    freopen("myOutput.txt","w", stdout);
//    freope
    sieve();
    findDiv();
//    printf("oka\n");
    int a,b,c;
    long long sum=0;
    scanf("%d %d %d",&a, &b, &c);
    for(int i=1; i<=a; i++)
    {
        for(int j=1; j<=b; j++)
        {
            for(int k=1; k<=c; k++) {
                int div = (i*j*k);
//                printf("num %d div %d\n",div, divs[div]);
                sum+= divs[div];
                if(sum> 1073741824) {
                    sum = (sum& 1073741823);
                }
            }
        }
    }
    printf("%I64d\n",sum);
    return 0;
}
