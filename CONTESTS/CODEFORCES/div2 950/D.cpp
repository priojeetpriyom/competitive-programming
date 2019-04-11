#include<bits/stdc++.h>

using namespace std;
typedef long long ll;


//int ara[1000];

int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;

    cin>>n;
    int len =n;

    int q;
    cin>>q;

    while(q--) {
        ll x;
        cin>>x;
        while(x%2==0) {
            x+= n - x/2;
        }

        cout<<(x+1)/2<<endl;

    }
//int q;

//cin>>q;

//while(q--) {
//    int x;
//
//    cin>>x;
//
//    cout<<ara[x]<<endl;
//
//}

    return 0;

}
