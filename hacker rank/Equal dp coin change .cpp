#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int dp [1011] , ara[10010];


int rec(int val) {
    if(val <=0) return (!val) ? 0: 1e9;

    int &ret = dp[val];
    if(ret!= -1) return ret;

    return ret = min(rec(val-5), min(rec(val-2), rec(val-1)) ) +1;

}



int main()
{
    memset(dp,-1,  sizeof dp);

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    cout<<rec(5)<<endl;
    int t, n;
    scanf("%d", &t);

    while(t--)
     {
        scanf("%d", &n);
        int mn = 1e9;
        for(int i=0; i<n; i++) {
            scanf("%d", &ara[i]);
            mn = min(mn, ara[i]);
        }
        int mn_ans=1e9;
        int cnt=5;
        while(cnt--) {
        int ans=0;
            for(int i=0; i<n; i++) {
            ans+= rec((ara[i]-mn) );
        }
        mn_ans = min(ans, mn_ans);
            mn--;
        }
        printf("%d\n", mn_ans);
     }

    return 0;

}
