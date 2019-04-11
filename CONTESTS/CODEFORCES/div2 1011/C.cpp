#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 1100
#define double long double

ll a[MX], b[MX];
ll n, weight;

bool ok(double fuel) {
    fuel -= (weight+fuel)/a[0];
    for(int i=1; i<n; i++) {
        fuel -= (weight+fuel)/b[i];
        fuel -= (weight+fuel)/a[i];
    }
    fuel -= (weight+fuel)/b[0];

    return (fuel> -1e-11);
}

double binary(double l, double h, double mid) {
    while(h-l > 1e-9) {
        mid = (l+h)/2;
        if(ok(mid)) {
            h = mid - 1e-10;
        } else
            l = mid + 1e-10;
    }
    if(!ok(h))
        h+= 1e-10;
    return h;
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

//    int n;
    cin>>n>>weight;

    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    for(int i=0; i<n; i++) {
        cin>>b[i];
    }
    for(int i=0; i<n; i++) {
        if(a[i]==1 || b[i]==1) {
            cout<<-1<<endl;
            return 0;
        }
    }

    cout<<setprecision(10)<<binary(0, 1e9, 1e9/2)<<endl;


    return 0;
}
