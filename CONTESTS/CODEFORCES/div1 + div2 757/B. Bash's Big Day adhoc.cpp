#include <bits/stdc++.h>
using namespace std;
int primes[5000], len_primes=0;
bool gen[100011];
void prime_gen()
{
    gen[1] = gen[0] = true;

    for(int i=4; i<100001; i+=2)
        gen[i] = 1;

    for(int i=3; i<1000; i+=2)
    {
        if(gen[i]==0)
        {
            for(int j = i*i; j<100001; j+=i)
            {
                gen[j] = 1;
            }
        }
    }

    primes[len_primes++] = 2;
    for(int i=3; i<10001; i+=2)
    {

        if(gen[i]==0)
        {

            primes[len_primes++] = i;
//        printf("prime %d\n", i);
        }
    }
}
int divs[100010];

void find_divs(int n)
{
    if(gen[n]==0)
    {
//        printf("%d is prime\n", n);
        divs[n]++;
        return;
    }

    int root = sqrt(n)+5;

    for(int i=0; n>1; i++)
    {
        if(n%primes[i] ==0)
        {
            divs[primes[i]]++;
            while(n%primes[i] ==0)
                n/=primes[i];

            if(gen[n]==0)
            {
//        printf("%d is prime\n", n);
                divs[n]++;
                return;
            }
        }
    }

}
int main()
{
//    freopen("myOut.txt", "w", stdout);
    prime_gen();
//    for(int i=316; gen[i]==1; i--)
//        printf("%d\n", i);
//    printf("gone\n");
    int n;
    cin>>n;
    int num;
    int i;

    for(int j=0; j<n; j++)
    {
        scanf("%d", &num);
        find_divs(num);
    }
    int ans = 0;
    for(int i=2; i<100001; i++)
    {
        ans = max(ans, divs[i]);
//        if(divs[i]>0)
//        printf("%d=> %d\n", i, divs[i]);
    }
    if(ans==0)
        ans=1;

//    for(int i=0; i<len_primes; i++)
//        printf("%d ", primes[i]);
//        printf("\n");
//        if(divs[primes[i]]>0)
//        printf("%d-> %d\n", primes[i], divs[primes[i]]);


    printf("%d\n", ans);
    return 0;
}


