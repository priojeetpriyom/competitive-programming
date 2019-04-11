#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll dp[100100] [2];
ll mod = 1e9+7;


ll rec(int n, int prev, int k)
{
    if(n==1) return k - prev;
    ll &ret = dp[n] [prev];

    if(ret != -1) return ret;

    ret = rec(n-1, prev & 1, k) + rec(n-1, 0, k) * (k-1);
    return ret  = ret %mod;
}



int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    ll n, k;
    cin>>n>>k;
    ll nn = n/2 + (n&1);
//    if(k<nn && k<3) {
//        cout<<0<<endl;
//        return 0;
//    }
    if(n==2 && k==1)
    {
        cout<<0<<endl;
        return 0;
    }
    if(n==1)
    {
        cout<<k<<endl;
        return 0;
    }
    ll sum=1;
    ll kk = k;
//    for(int i=0; i<nn; i++)
//    {
//        sum*=kk;
//        kk = max(k-1, kk-1);
//        sum%=mod;
//    }
    sum  = rec(n-2,1,k );

    sum = (sum*k) %mod;

    sum = (sum* (k-1) ) %mod;

//    if(n&1) sum =  (sum * ( (n>5) ? k-1 : kk ) ) %mod;

    cout<<sum<<endl;
    return 0;
}


