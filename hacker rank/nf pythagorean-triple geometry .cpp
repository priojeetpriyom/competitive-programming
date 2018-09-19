#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

//#include <stdio.h>
//#include <string.h>
//#define ll long long

map<int, int> mp;


ll valid(ll c, ll a) {
    ll b = (c*c) - (a*a);
    ll r = sqrt(b);
    if(b == r*r) return r;

    return 0;
}

vector<ll> vec;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    for(ll i=1; i<=10000000; i++) vec.push_back(i*i);

    ll x;
    cin>>x;
    vector<ll> :: iterator it = upper_bound(vec.begin(), vec.end(), x);

    int i = distance(vec.begin(), it);
//    cout<<"i "<<i<<endl;;
    for( ; ; i++) {
        printf("i %d vec[i] %lld\n", i, vec[i]);
        if(valid(vec[i], x)) {
            cout<<x<<" "<<valid(vec[i], x)<<" "<<vec[i]<<endl;
            return 0;
        }
    }


    return 0;
}

