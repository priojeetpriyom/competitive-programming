#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100

ll n, m, k, mod = 1e9+7;


ll BigMod(ll num, ll pw) {
    if(!pw)
        return 1LL;
    ll ret;

    ret = BigMod(num, pw/2);
    ret*=ret;
    if(ret>=mod)
        ret%=mod;
    if(pw&1) {
        ret *= num;
    }
    if(ret>= mod)
        ret %=mod;
    return ret;

}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m>>k;
    if( ( (n+m) &1 ) && k==-1) {
        cout<<0<<endl;
        return 0;
    }
//    ll pw=0;
////    pw+= (n-1);
//    pw= ( (n-1)%mod) * ( (m-1)%mod );
//    if(n<=2 || m<=2)
//        pw=0;
//    cout<<pw<<endl;
//    if(!pw)
//        cout<<1<<endl;
//    else
        cout<<BigMod(BigMod(2, n-1),m-1);



    return 0;
}


