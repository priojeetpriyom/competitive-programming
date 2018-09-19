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

string l,r;
ll dp[70][4][4][4][4];
ll path[70];
string get_string(ll val) {
    string ret;
    do{
        ret+= (val&1) + '0';
        val>>=1;
    } while(val);
    reverse(ret.begin(), ret.end());
    return ret;
}


ll pw(ll pos) {
    return (1<<(l.size()-pos-1))%mod;
}
ll rec(int pos, int l1, int r1, int l2, int r2) {
//    cout<<"pos "<<pos<<endl;
    if(pos == r.size())
        return 0;
    ll &ret = dp[pos] [l1] [r1][l2][r2];
    if(~ret)
        return ret;
    vector<int> posl, posr;

    // pushing 0
    if(l[pos]=='0') {
        posl.push_back(0);
        posr.push_back(0);
    } else{
        if(l1)
            posl.push_back(0);
        if(l2)
            posr.push_back(0);
    }

    //pushing 1
    if(r[pos]=='1') {
        posl.push_back(1);
        posr.push_back(1);
    } else {
        if(r1)
            posl.push_back(1);
        if(r2)
            posr.push_back(1);
    }
    ll cur=0;
    for(auto i: posl) {
        for(auto j : posr) {
            ret = max(ret, rec(pos+1, l1 | (l[pos]=='0' && i==1), r1| ((r[pos]=='1'&& i==0) ), l2 | (l[pos]==0 && j==1),  r2 | (r[pos]=='1' && j==0)));
            cur = max(cur,(ll) i^j);
        }
    }
//    cout<<"pos "<<pos<<" cur "<<cur<<endl;
//    for(auto i: posl)
//        cout<<i<<" ";
//    cout<<" L"<<endl;
//    for(auto i: posr)
//        cout<<i<<" ";
//    cout<<" R"<<endl;
    ret = (ret + cur*pw(pos))%mod;
    path[pos] = max(cur, path[pos]);
    return ret;
}




ll solve() {

    ll L,R;
    cin>>L>>R;
//    L=1;
//    R=1e18;
    l=get_string(L);
    r = get_string(R);
    while(l.size()<r.size()) {
        l.insert(0, "0");
    }
//    cout<<"l: "<<l<<endl;
//    cout<<"r: "<<r<<endl;
    rec(0, 0, 0, 0, 0);

    ll ans=0, p=1;

    for(int i = l.size()-1; i>=0; i--) {
        ans += ( (path[i]* p));
//        ans%=mod;
        p = p<<1;
    }

    return ans;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    memset(dp, -1, sizeof dp);

    int t=1;
//    cin>>t;

    for(int tc=1; tc<=t; tc++) {

//        cout<<"Case #"<<tc<<": ";
        cout<<solve()<<endl;
//    printf("%lld\n", solve());
    }

    return 0;
}
