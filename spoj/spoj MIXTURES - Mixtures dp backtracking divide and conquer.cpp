#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct node {
    int s, c;
};

int ara[111];
node dp[111] [111];

node rec(int beg, int endd) {
    node ans, l,r;
    if(beg == endd) {
        ans.c = ara[beg]; ans.s=0;
        return ans;
    }

    node &ret = dp[beg] [endd];
    if(ret.s != -1) return ret;
    ret.s = 1e10;
    for(int mid = beg; mid<endd; mid++) {
        l = rec(beg, mid);
        r = rec(mid+1, endd);
        ans.c = (l.c + r.c)%100;
        ans.s = l.s + r.s + (l.c * r.c);
        if(ans.s < ret.s) {
            ret = ans;
        }
    }
    return ret;
}




int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin>>n) {
        memset(dp, -1, sizeof dp);
        for(int i=1; i<=n; i++) cin>>ara[i];

        cout<<rec(1,n).s<<endl;

    }





    return 0;
}

