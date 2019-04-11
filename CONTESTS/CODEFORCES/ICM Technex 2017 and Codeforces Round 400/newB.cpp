#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ara[100100], primes[10000], len_primes=0;
int gen[100100];
void prime_gen(int n)
{
    int root = sqrt(n);
//    printf("oka");

    for(int i=2; i<100100; i++)
    {
        if(!gen[i] && i<10000)
        {
            for(int j = i*i; j<n; j+=i)
            {
                gen[j] =1;
            }
        }
    }
    int cnt=0;
    for(int i=2; i<100100; i++)
        if(!gen[i])
            primes[len_primes++] = i;


}

int main()
{
//    freopen("out.txt", "w", stdout);
    prime_gen(100100);


//    for(int i=0; i<100; i++)
//        printf("%d ", primes[i]);

    int n;
    cin>>n;
    int lim = n+1;
    int mx = -1;
    for(int i=0; primes[i]<= lim; i++)
    {
//        int x=1;
//        map<int, int>mp;
//        printf("prime %d\n", primes[i]);
        for(int j = primes[i] ; j<=lim; j+= primes[i])
        {
            if(ara[primes[i]] == ara[j])
            {
                ara[j]++;
//                x++;
            } else if(ara[j]==0) {
                ara[j]= ara[primes[i]]+1;
            }
        }

//        for(int i=2; i<=lim; i++)
//            printf("%d,%d  ", i, ara[i]);
//        printf("\n");

//        printf("map size %d\n", mp.size());
//        int y = mp.size();
//        mx = max(mx, x);
    }
    mx = -1;

    for(int i=2; i<=lim; i++)
        mx = max(mx, ara[i]);
//    for(int i=2; i<=lim; i++)
//        if(ara[i] ==0)
//            ara[i] = 1;
    printf("%d\n", mx);
    for(int i=2; i<=lim; i++)
        printf("%d ",max(ara[i],1));
        printf("\n");

//
//                for(int i=2; i<=lim; i++)
//            printf("%d,%d  ", i, ara[i]);
//        printf("\n");

    return 0;
}



