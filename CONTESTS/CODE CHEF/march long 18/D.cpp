#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100
ll ara[MX];
ll n, h;


bool is_ok(int k) {


    ll sum=0;

    for(int i=0; i<n; i++) {

        sum+= (( ara[i]+k-1 )/k);
    }
//    cout<<"k "<<k<<" sum "<<sum<<" h"<<h<<endl;
    return sum<=h;

}


int bsearch(int low, int high, int mid)
{

    while(low<=high) {
        mid = (high+low)/2;
        if(is_ok(mid))
            high = mid-1;
        else
            low = mid+1;

    }
//    cout<<"high after search "<<high<<endl;
    if(is_ok(high))
        return high;

    return high+1;

}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    int t;
    cin>>t;

    while(t--) {

        cin>>n>>h;
        for(int i=0; i<n; i++)
            cin>>ara[i];

        cout<<bsearch(1, 1e9, 1e9/2)<<endl;

    }



    return 0;
}


