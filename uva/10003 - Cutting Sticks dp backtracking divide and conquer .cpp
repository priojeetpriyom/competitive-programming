#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int n;
int ara[55];
int dp[1010] [1010], vis[55];

int rec(int beg, int endd) {
//    printf("beg %d endd %d\n", beg, endd);
    int &ret = dp[beg] [endd];
    if(ret != -1) {
//        printf("beg %d end %d RETURNED %d\n", beg, endd, ret);
        return ret;
    }
    ret = 1e8;
    for(int i=0; i<n; i++) {
        if(ara[i]>=beg && ara[i]<=endd && !vis[i ] ) {
            vis[i ]=1;
            ret = min(ret, rec(beg, ara[i])+ rec(ara[i]+1, endd)+ endd-beg+1 );
            vis[i ]=0;
        }
    }

    if(ret==1e8) ret =0;
//    printf("beg %d endd %d ret %d\n", beg, endd, ret);
    return ret;

}




int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);cin.tie(0);

    int l;

    while(cin>>l && l) {
        memset(dp, -1, sizeof dp);
        cin>>n;

        for(int i=0; i<n; i++)
            cin>>ara[i];

        cout<<"The minimum cutting is "<<rec(1, l)<<"."<<endl;

    }



    return 0;
}

