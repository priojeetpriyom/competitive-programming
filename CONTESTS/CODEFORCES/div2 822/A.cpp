#include <bits/stdc++.h>

using namespace std;
typedef long long ll;





int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll a,b;
    cin>>a>>b;
    if(a>b) swap(a,b);
    ll ans=1;
    while(a>1) {
        ans*=a;
        a--;
    }
    cout<<ans<<endl;

    return 0;
}


