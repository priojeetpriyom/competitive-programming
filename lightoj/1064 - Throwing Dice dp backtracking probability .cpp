#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 105

ull n, x, dp[30][155];
int vis[30] [155], tc;


ull rec(ull n, ull val) {
//    if(val<=0) return 1;
    if(!n)
        return (val>=x);
    ull& ret = dp[n][val];

    if(vis[n] [val] == tc)
        return ret;
    ret=0;
    vis[n][val]= tc;

    for(int i=1; i<=6; i++)
        ret += rec(n-1, val+i);

    return ret;
}





int main()
{
//    freopen("out.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(false);

    int t;
    cin>>t;

    for(tc=1; tc<=t; tc++) {
        ull tot =1;
        cin>>n>>x;
        for(int i=1; i<=n; i++)  {
            tot*= 6;
        }
        ull ret = rec(n, 0);
        while(__gcd(tot, ret)!=1) {
            ull temp = __gcd(tot, ret);
            tot/=temp;
            ret/=temp;
        }
        if(ret==0 || ret==tot)
            cout<<"Case "<<tc<<": "<<ret<<endl;
        else
            cout<<"Case "<<tc<<": "<<ret<<"/"<<tot<<endl;
    }



    return 0;
}
