#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100




int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll   y,b;
    ll x, yy, z;
    ll reqy=0, reqb=0;

    cin>>y>>b;
    cin>>x>>yy>>z;

    reqy = 2*x+ 1*yy;
    reqb = 1*yy+ 3*z;

    cout<<max(0LL, reqy-y) + max(0LL, reqb-b)<<endl;;



    return 0;
}


