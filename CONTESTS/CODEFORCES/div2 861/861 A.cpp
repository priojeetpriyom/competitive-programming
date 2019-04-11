#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main()
{
//    cout<<ceil(10/2);

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, k;
    cin>>n>>k;

    ll pw=1;
    for(int i=0; i<k; i++)
        pw*=10;

    cout<<(pw*n)/ __gcd(pw, n)<<endl;
    return 0;
}


