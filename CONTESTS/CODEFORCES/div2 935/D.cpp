#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100
#define mod 1000000007
ll dp[MX][5];

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

ll n, m;

ll makeMod(ll num)
{

    return ((num>=mod)?num%mod: num);

}

ll rec(int pos, int is_bigger)
{
//    cout<<"pos "<<pos<<" is_bigger "<<is_bigger<<endl;
    if(is_bigger==-1)
        return 0;
    if(pos==n)
        return (ll)is_bigger;
    ll &ret = dp[pos][is_bigger];
    if(~ret)
        return ret;
    if(s1[pos]==0 && s2[pos]==0)
    {
        if(is_bigger)
        {
            ret = makeMod(rec(pos+1, is_bigger) * makeMod(m*m));
        }
        else
        {
            ret = makeMod((((m*(m-1))/2)*rec(pos+1, true))+ makeMod(m* rec(pos+1, is_bigger)));
        }
    }
    else if(s1[pos]==0)
    {
        if(is_bigger)
        {
            ret = makeMod(m* rec(pos+1, is_bigger));
        }
        else
        {
            ret = makeMod( makeMod( (m-s2[pos])*rec(pos+1, true) ) + rec(pos+1, is_bigger));
        }
    }
    else if(s2[pos]==0)
    {
        if(is_bigger)
        {
            ret = makeMod(m* rec(pos+1, is_bigger));
        }
        else
        {
            ret = makeMod( makeMod( (s1[pos]-1)*rec(pos+1, true) ) + rec(pos+1, is_bigger));
        }
    }
    else
    {
        if(s1[pos]>s2[pos])
            ret = rec(pos+1, true);
        else if(s1[pos]<s2[pos])
            ret = rec(pos+1, (is_bigger==1)?is_bigger:-1 );
        if(s1[pos]==s2[pos])
            ret = rec(pos+1, is_bigger);
    }
    return ret;


}


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

//    ll n, m;
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
//    for(int i=0; i<n; i++)
//    {
//        if(s1[i]==0 && s2[i]==0)
//        {
//            up *= ((m*(m-1))/2);
//            if(up>=mod)
//                up%=mod;
//        }
//        else if(s1[i]==0)
//        {
//            ll x = m- s2[i];
//            up*= x;
//            if(up>=mod)
//                up%=mod;
//            down *= ( (m>=mod)? bigMod(m, mod-2): m);
//            if(down>=mod)
//                bigMod(down, mod-2);
//            cout<<"s1 up "<<up<<" down "<<down<<endl;
//        }
//        else if(s2[i]==0)
//        {
//
//            ll x = s1[i]-1;
//            up*= x;
//            if(up>=mod)
//                up%=mod;
//            down *= ( (m>=mod)? bigMod(m, mod-2): m);
//            if(down>=mod)
//                bigMod(down, mod-2);
//        }
//
//    }
    memset(dp, -1, sizeof dp);
    up =rec(0, 0);
    ll zcnt=0;
    for(int i=0; i<n; i++)
    {
        zcnt+= (s1[i]==0)+ (s2[i]==0);
    }
//    cout<<"zero "<<zcnt<<endl;

    down = bigMod(m, zcnt);

//    down = bigMod(down, mod-2);

//    cout<<up<<" "<<down<<endl;
    down = bigMod(down, mod-2);
    up*= down;
    if(up>=mod)
        up%=mod;

    cout<<up<<endl;

    return 0;
}


