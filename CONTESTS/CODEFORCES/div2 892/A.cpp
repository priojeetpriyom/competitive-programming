#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100


vector<ll> vec;
ll sum;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        ll x;
       cin>>x;
        sum+=x;
    }

    for(int i=0; i<n; i++)
    {
        ll x;
        cin>>x;
        vec.push_back(x);

    }
    sort(vec.begin(), vec.end());

    if(vec[n-1] + vec[n-2] >= sum) {
        cout<<"YES"<<endl;
    }else
        cout<<"NO"<<endl;


    return 0;
}


