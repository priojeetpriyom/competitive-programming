#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


string s;
ll len, dp[100100] [4];


ll rec(int pos, int mod) {
    if(pos == len)
        return 0;

    ll &ret = dp[pos] [mod];

    if(ret != -1) return ret;

    ret = rec(pos+1, (mod+ s[pos])%3) + (((mod+ s[pos])%3 ==0) && ((s[pos])%2==0));
    return ret;
}


int main()
{
//        freopen("out.txt", "w", stdout);
    memset(dp, -1, sizeof dp);
    cin>>s;
    len = s.length();
    ll ans=0;
    for(int i=0; i<len; i++) {
        if(s[i]=='0')
            ans++;
        else
            ans+=rec(i,0);
    }
    cout<<ans;

    return 0;
}


