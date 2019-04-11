#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll f[1111], f_1[1111], f_2[1111];
vector<ll> primes;
int len_primes;
int gen[1111];
void prime_gen()
{



    for(int i=3; i<101; i+=2)
        if(!gen[i])
            for(int j = i*i; j<101; j+=i)
                gen[j]=1;

    primes.push_back(2);

    for(int i=3; i<101; i+=2)
        if(!gen[i]) primes.push_back(i);
    len_primes = primes.size();
}

void fact(int n, ll ara[]) {


    for(int i=0; i<len_primes; i++) {
        while(n%len_primes==0) {
            ara[primes[i]]++;
            n/= primes[i];
        }
    }
    if(n>1) ara[n]++;
}




int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);
    prime_gen();
    int t;
    int n, a, b;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%d %d %d", &n, &a, &b);

        for(int i=0; i<1011; i++) f[i] = f_1[i] = f_2[i]=0;
        fact(a, f_2); fact(b, f_1);

        for(int i=2; i<=n; i++) {
            for(int i=0; i<1001; i++) {
                f[i] = f_1[i] + f_2[i];
            }

            for(int i=0; i<1001; i++) {
                f_2[i] = f_1[i];
            }
            for(int i=0; i<1001; i++) {
                f_1[i] =  f[i];
            }


        }


            for(int i=0; i<1001; i++) {
                if(f[i])
                printf("%d %lld\n", i , f[i]);
            }




        printf("\n");
    }



    return 0;

}

