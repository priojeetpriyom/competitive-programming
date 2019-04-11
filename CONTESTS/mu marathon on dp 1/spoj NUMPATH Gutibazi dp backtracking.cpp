
#include <bits/stdc++.h>

using namespace std;
//
//#include <stdio.h>
//#include <string.h>

int dp[10] [10];

int rec(int r, int c) {
//    printf("r %d c %d\n", r, c);
    if(r==1 && c==1) return 1;
    if(!r || !c) return 0;

    int &ret = dp[r][c];
    if(ret != -1 ) return ret;

    return ret = rec(r-1, c) + rec(r, c-1);


}




int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    int t;

    cin>>t;

    int n,m;
    memset(dp, -1, sizeof dp);

    while(t--) {
        cin>>n>>m;
        cout<<rec(n, m)<<endl;
    }


    return 0;
}
