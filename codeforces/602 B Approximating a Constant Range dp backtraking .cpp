#include <bits/stdc++.h>

using namespace std;


int n, ara[100100];
int dp[100100] [10];
int base=5;

int rec(int pos, int diff) {
//    printf("pos %d diff %d\n", pos, diff);
    if(pos == n || (diff == ara[pos] && diff != 2) ) return 0;

    int &ret = dp[pos] [diff];
    if(ret != -1) return ret;

    return ret = rec(pos+1, (ara[pos]==2)? diff: ara[pos] )+1;

}



int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin>>n;

    for(int i=0; i<n; i++) cin>>ara[i];

    for(int i = n-1; i>0; i--) ara[i] = ara[i]- ara[i-1]+2;
//    ara[0]=0;
    int ans=0;
    for(int i=0; i<n && ans!=n; i++) {
        ara[i]=0;
        ans = max(ans, rec(i, 2));
//        printf("i %d rec %d\n", i, rec(i,2));
    }
    cout<<ans;

    return 0;
}

