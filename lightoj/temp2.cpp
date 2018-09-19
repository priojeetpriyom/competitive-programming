#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100
#define mod 1000000007

ll bigMod(ll a, ll b)
{

    if(b==0)
        return 1;

    ll ret = bigMod(a, b/2);
    ret*=ret;

    if(ret>=mod)
        ret%=mod;

    if(b&1)
        ret*=a;
    if(ret>=mod)
        ret%=mod;

    return ret;

}
vector<ll> s1(100100), s2(100100);

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin>>n>>m;
    ull up=1, down=1;

    for(int i=0; i<n; i++)
    {
        cin>>s1[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>s2[i];
    }
    for(int i=0; i<n; i++)
    {
        if(s1[i]==0 && s2[i]==0)
        {
            up *= ((m*(m-1))/2);
            if(up>=mod)
                up%=mod;
            down  = bigMod(down*m, mod-2);
            down  = bigMod(down*m, mod-2);
        }
        else if(s1[i]==0)
        {
            ll x = m- s2[i];
            up*= x;
            if(up>=mod)
                up%=mod;
            down  = bigMod(down *m, mod-2);
//            if(down>=mod)
//                bigMod(down, mod-2);
            cout<<"s1 up "<<up<<" down "<<down<<endl;
        }
        else if(s2[i]==0)
        {

            ll x = s1[i]-1;
            up*= x;
            if(up>=mod)
                up%=mod;
            down  = bigMod(down *m, mod-2);
        }

    }
    cout<<up<<" "<<down<<endl;
//    down = bigMod(down, mod-2);
    up*= down;
    if(up>=mod)
        up%=mod;

    cout<<up<<endl;

    return 0;
}



