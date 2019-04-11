#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);


    int t;

    cin>>t;

    for(int tc=1; tc<=t; tc++) {
        ll m,n=0, k=0;
        cin>>m;
        int x;

        for(int i=0; i<m; i++) {
            cin>>x; n+=x;
            cin>>x; k+=x;
        }
//        cout<<"n "<<n<<"k "<<k<<endl;
        k*=m;
//        cout<<"n "<<n<<"k "<<k<<endl;

        while(__gcd(n,k)!= 1) {
            x = __gcd(n,k);
            n/= x;
            k/= x;
        }

        cout<<"Case "<<tc<<": ";
        cout<<k<<"/"<<n<<endl;
    }


    return 0;
}
