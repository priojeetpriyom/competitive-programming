#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 55

ll n, dp[205][15][25] [25], ara[205];
//string a, b, c;
ll vis[205][15][25] [25], tc,xx=1;
ll d, m;

ll modd(ll val, ll moder) {
//    return val%moder;
    return ( (val %moder)+ moder)%moder;
}

ll process(ll a, ll b) {
//    if(abs(a)>=d)
//        a%=d;
//    if(abs(b)>=d)
//        b%=d;
    a = modd(a, d);
    b = modd(b, d);
    return modd(a+b, d);
}

ll rec(ll pos, ll cnt, ll sum, ll mod) {
    ll &ret = dp[pos] [cnt] [sum] [mod];
    if(pos == n && cnt == m && modd(sum ,mod)==0)
        return 1;
    if(pos==n || cnt==m+1) // || n - pos > m - cnt)
        return 0;


    if(vis[pos] [cnt] [sum] [mod] == xx)
        return ret;
    ret=0;
    vis[pos] [cnt] [sum] [mod]= xx;

//    for(ll i = pos; i<n; i++)
        ret = (rec(pos+1, cnt+1, process(sum, ara[pos]), mod) +rec(pos+1, cnt, (sum), mod) );

    return ret;
}





int main()
{
//    cout<<-13%5;
//    freopen("out.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(false);

    ll t, q;
    cin>>t;
    cin.ignore();
    for(tc=1; tc<=t; tc++) {
        cin>>n>>q;
        for(ll i=0; i<n; i++)
            cin>>ara[i];
//        for(ll i=0; i<n; i++)
//            cout<<ara[i]<<endl;
        cout<<"Case "<<tc<<":"<<endl;

        while(q--) {
            cin>>d>>m;
            cout<<rec(0, 0, 0, d)<<endl;
            xx++;
        }
//        cout<<a<<","<<b<<","<<c<<endl;
//        if(ret==0 || ret==tot)
//        else
//            cout<<"Case "<<tc<<": "<<ret<<"/"<<tot<<endl;
    }



    return 0;
}
