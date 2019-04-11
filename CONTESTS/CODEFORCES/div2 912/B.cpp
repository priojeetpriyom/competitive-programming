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

    ll n, k;

    cin>>n>>k;

    if(k==1)
        cout<<n<<endl;
    else {
        ll ans=1;

        while(ans<=n)
            ans<<=1;

        cout<<ans-1<<endl;


    }



    return 0;
}


