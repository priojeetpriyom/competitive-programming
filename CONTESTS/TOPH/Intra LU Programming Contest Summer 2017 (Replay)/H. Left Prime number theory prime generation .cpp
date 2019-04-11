#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

//#include <stdio.h>
//#include <string.h>
//#define ll long long
int gen[10001000], primes[10001000];

//vector<int> primes;

void prime_gen()
{
    gen[1] = gen[0]=1;
    for(int i=4; i<10000010; i+=2) gen[i]=1;

    for(int i=3; i<4000; i+=2)
    {
        if(!gen[i])
            for(int j = i*i; j<10000001; j+=i)
                gen[j]=1;
    }
    int cnt=0;
//        primes[3]=1;
    for(int i=2; i<10000001; i++ )
    {
        primes[i] += primes[i-1]+ (!gen[i-1] );
//        cnt+= !gen[i];
    }
//    printf("cnt %d\n", cnt);

}





int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    prime_gen();
    int t, n;
    cin>>t;
//    vector<int>:: iterator it;

    while(t--)
    {
        scanf("%d", &n);

//        int pos = get_pos(0, primes.size()-1, n);
//        printf("aise %d\n", pos);
//
//        while(primes[pos]>=n) {
////            printf("pos %d\n", pos);
//            pos--;
//        }


        printf("%d\n", primes[n]);


    }


    return 0;
}
