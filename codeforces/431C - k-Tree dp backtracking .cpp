#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 110
#define MOD 1000000007


ll dp [MX] [MX] [3];
int n, k,d;

ll rec(int left, int sum, int is_greater) {
    if(sum==0)
        return is_greater;
    if(sum<0 || !left)
        return 0;

    ll &ret= dp[left] [sum] [is_greater];
    if(~ret)
        return ret;
    ret=0;

    for(int i = k; i>=1; i--)
        ret+= rec(left-1, sum-i , is_greater | (i>=d));
    if(ret>= MOD)
        ret%=MOD;
    return ret;
}


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof dp);

    cin>>n>>k>>d;
    cout<< rec(100, n, 0);




    return 0;
}


