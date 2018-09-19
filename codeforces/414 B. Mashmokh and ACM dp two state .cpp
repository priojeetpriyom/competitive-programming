/*
    algo:
    idea:

*/
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 2022
#define mod 1000000007

int n, k;

ll dp[MX] [MX];

ll rec(int left, int last) {
    // cout<<"left "<<left<<" last "<<last<<endl;
    if(last>n)
        return 0LL;
    if(!left) {
        return 1LL;
    }

    ll &ret = dp[left] [last];
    if(~ret)
        return ret;
    ret=0;

    for(int i = last; i<=n; i+=last) {
        ret+= rec(left-1, i);
        if(ret>=mod)
            ret%=mod;

    }
//    cout<<"left "<<left<<" last "<<last<<" ret "<<ret<<endl;


    return ret;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//freopen("output.txt", "w", stdout);
    memset(dp, -1, sizeof dp);
   cin>>n>>k;
    // n=k=2000;
    cout<<rec(k, 1)<<endl;
    // cout<<"EXECUTION FINISHED";
    return 0;
}
