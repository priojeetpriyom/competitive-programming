#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100

bool is_prime(int n) {

    int root = sqrt(n)+1;

    for(int i=2; i<root; i++)
        if(n%i==0)
            return false;

    return true;

}
int primes[100], len_primes;
map<int, 1> not;
int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, k;

    for(int i=2; i<=100; i++){

        if(is_prime(i))
        primes[len_primes++] = i;
    }

    cin>>n>>k;


    for(int i=0; i<n; i++) {
        cin>>
    }




    return 0;
}


