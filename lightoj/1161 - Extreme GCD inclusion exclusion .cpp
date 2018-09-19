/*
    algo:
    idea:

*/
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 100100
#define mod 1000000007

ll cnt[10010],res[10010], ncr[100100] [ 5];

ll nCr(ll n, ll r) {
    if(n<r)
        return 0;
    if(n==r)
        return 1;
    if(r==1)
        return n;
    ll &ret = ncr[n][r];
    if(~ret)
        return ret;
    return ret = nCr(n-1, r-1) + nCr(n-1, r);
}

ll solve() {
    memset(cnt, 0, sizeof cnt);
    memset(res, 0, sizeof res);
    int n, x, mx=0;
    cin>>n;
    for(int i=0; i<n; i++ ){
        cin>>x;
        cnt[x]++;
        mx = max(mx, x);
    }
//    ll ans=0;
    for(int i=mx; i>0; i--) {
        ll cum=0;
//        if(!cnt[i])
//            continue;
        cum+= cnt[i];
        for(int j = i+i; j<=mx; j+=i) {
            res[i]-= res[j];
            cum+= cnt[j];
        }
//        cout<<"i "<<i<<" cum "<<cum<<" ncr "<<nCr(cum, 4)<<endl;
        res[i]+= nCr(cum, 4);
    }




    return res[1];

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    memset(dp, -1, sizeof dp);
    memset(ncr, -1, sizeof ncr);
    nCr(10000, 4);

//    cout<<nCr(6,4)<<endl;

    int t=1;
    cin>>t;

    for(int tc=1; tc<=t; tc++) {

//        cout<<"Case #"<<tc<<": ";
        cout<<"Case "<<tc<<": ";
        cout<<solve()<<endl;
//    printf("%lld\n", solve());
    }

    return 0;
}
