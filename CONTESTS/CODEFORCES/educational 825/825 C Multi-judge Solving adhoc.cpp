#include <bits/stdc++.h>

using namespace std;
typedef long long ll;





int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);


    ll n, k, x, mx=0;

    cin>>n>>k;
    ll ara[1111];

    for(int i=0; i<n; i++)
    {
        cin>>ara[i];
//        mx = max(mx, x);
    }
    sort(ara, ara+n);

    mx = k;
    int cnt=0;
    for(int i=0; i<n; i++) {
        while(mx+mx< ara[i]) {
            mx+=mx;
            cnt++;
        }
        mx = max(mx, ara[i]);
    }

    cout<<cnt<<endl;



    return 0;
}


