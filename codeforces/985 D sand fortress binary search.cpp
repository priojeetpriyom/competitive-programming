#include <bits/stdc++.h>
using namespace std;

#define MX 100010
#define ll long long
ll ara[MX];
queue<ll> fao;


bool isEven(double tot);

double get_seq_sum(double n) {
    return round( (n*(n+1))/2 );
}


double calc(double space, double height) {
    if(height>=space) {
        return get_seq_sum(space);
    }

    double pre_height = height-1;
    double  tot = space+ pre_height;

    double sum=0;

    sum = 2* get_seq_sum(((ll)tot)/2);
    if(!isEven(tot)) {
        sum+= ((( (ll)tot)/2)+1);
    }
//    cout<<"space "<<space<<" pre_height "<<pre_height<<" sum "<<sum<<" pre_sum "<<get_seq_sum(pre_height)<<endl;
    return sum - get_seq_sum(pre_height);

}

bool isEven(double n) {
    ll a = n;
    return (a%2==0);
}


ll Bsearch(double n, ll h) {
    ll high = 1e15, low = 1, mid;

    while(low<=high) {
        mid = (high+low)/2;
        if(calc(mid, h) >=n)
            high = mid-1;
        else
            low = mid+1;
    }
    while(calc(high, h)<n)
        return high+1;
    return high;
}


int main() {

    ll n, h;

    cin>>n>>h;
    ll ans = Bsearch(n,h);
    cout<<ans<<endl;

//    double check = n;
//    if(get_seq_sum(ans)>=check) {
//        cout<<"ans oka"<<endl;
//    }

    return 0;
}
