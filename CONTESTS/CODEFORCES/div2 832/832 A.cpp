#include <bits/stdc++.h>

using namespace std;
typedef long long ll;





int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, k;
    cin>>n>>k;

    if((n/k)&1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;


    return 0;
}


