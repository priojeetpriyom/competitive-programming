#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


unordered_map<ll, ll> mp;

int main()
{


//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);


    ll t, u,v;

    ll rankk=0;

    ll  sum=1, freq=1;

//    while(rankk<=1e5) {
//        sum+= rankk ;
//        mp[rankk] = sum;
////        printf("rankk %lld sum %lld\n", rankk, sum);
////        freq
//        rankk++;
//    }


    cin>>t;

    while(t--) {

        cin>>u>>v;
        ll n = u+v;

        n = (n*n)/2 + (n/2) +1 + (n&1);

        cout<<n + u <<endl;
    }

    return 0;
}





