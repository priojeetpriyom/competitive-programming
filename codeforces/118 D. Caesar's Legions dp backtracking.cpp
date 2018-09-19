#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int lim =1e8;

int N1,N2,K1, K2;
ll dp[101] [101] [11] [11];

ll rec(int n1, int n2, int k1, int k2) {
    if(n1<0 || n2<0 || k1>K1 || k2>K2)
        return 0;
    if(!n1 && !n2) return 1;

    ll &ret = dp[n1][n2][k1][k2];
    if(ret != -1) return ret;

    ret = rec(n1-1, n2, k1+1, 0) + rec(n1, n2-1, 0, k2+1);
    if(ret > lim)
        ret %= lim;
    return ret;
}


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    memset(dp, -1, sizeof dp);
    cin>>N1>>N2>>K1>>K2;
    cout<<rec(N1, N2, 0, 0);

    return 0;
}



