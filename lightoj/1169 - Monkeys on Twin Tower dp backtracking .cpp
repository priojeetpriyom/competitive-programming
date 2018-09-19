#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 55

int n, tc;
int dp[1010] [5], vis[1010] [5];

int eat[5] [1010], change[5][1010];

int rec(int pos, int side) {
    if(pos == n)
        return 0;
    int &ret = dp[pos] [side];

    if(vis[pos] [side] == tc)
        return ret;
    vis[pos] [side] = tc;

    ret = min(rec(pos+1, side), rec(pos+1, side^1)+ change[side] [pos] )+ eat[side] [pos];

    return ret;
}





int main()
{
//    cout<<-13%5;
//    freopen("out.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(false);

    ll t, q;
    cin>>t;
    cin.ignore();
    for(tc=1; tc<=t; tc++) {
        memset(vis, -1, sizeof vis);
        cin>>n;

        for(int i=0; i<2; i++) {
            for(int j=0; j<n; j++) {
                cin>>eat[i][j];
            }
        }
        for(int i=0; i<2; i++) {
            for(int j=0; j<n-1; j++) {
                cin>>change[i][j];
            }
        }


        cout<<"Case "<<tc<<": "<<min(rec(0, 0), rec(0,1))<<endl;

//        cout<<a<<","<<b<<","<<c<<endl;
//        if(ret==0 || ret==tot)
//        else
//            cout<<"Case "<<tc<<": "<<ret<<"/"<<tot<<endl;
    }



    return 0;
}

