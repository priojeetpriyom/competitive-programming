#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

double ara[1010], t, d[1010], s[1010];
ll dist, speed;
    int n;

bool valid(double c) {
    double ans=0;
    for(int i=0; i<n; i++) {
        if(s[i]+c <=0) return true;
        ans+= (d[i]/ (s[i]+c));
    }
//    printf("ans %.10lf\n", ans);
    return ans > t;
}


double bin_search(double high, double low, double mid) {
    while(high - low >= .0000000001) {
//    printf("high %.10lf low %.10lf mid %.10lf \n", high, low, mid);
        mid = (high+low)/2;
        if(valid(mid)) {
            low = mid + .0000000001;
        } else high = mid- .0000000001;
    }
    return mid;
}


int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>t;
    ll x, y;
    for(int i=0; i<n; i++) {
        cin>>d[i]>>s[i];
//        dist+=x;
//        speed+=y;
    }
//    printf("dist %lld speed %lld\n", dist, speed);
    double ans = bin_search(1000000000, -1000000000, 0);

    if(abs( (double)0 - abs(ans) )<=.0000001 ) ans=0;
    printf("%.9lf\n",ans);


    return 0;

}


