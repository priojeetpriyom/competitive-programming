#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double dll;

ll n, cost;


ll calc(ll mid) {

    return (mid * ( (n-mid)/cost ) );


}


ll bin_search() {

    ll high = n, low =1, mid = (high+low)/2;
    ll l=0,h=0;
    ll mx=0;
    while(low<=high) {
        mid = (high+low)/2;
//        printf("low %lld high %lld mid %lld\n", low, high, mid);
        l = calc(low);
        h = calc(high);
        if(calc(mid)<l) high = mid-1;
        else low = mid+1;

        mx = max(mx, max(calc(mid), max(l,h)));

    }

    return mx;
}


int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);  cin.tie(0);


    int t;
    cin>>t;


    while(t--) {

        cin>>n>>cost;

        if(n<=cost) {
            cout<<0<<endl;continue;
        }

        ll b_cost = max(1LL, (ll)round( (  (dll)n/cost)/2) );

        ll ans = (n- (b_cost* cost) ) * b_cost;
        cout<<ans<<endl;
    }


    return 0;

}

