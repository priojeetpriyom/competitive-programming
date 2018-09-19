#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 105

int n, lenAra, ara[12], dp[12][12];
int vis[12] [12], tc;


ull rec(int pos, int prev) {
    int &ret = dp[pos] [prev];
    if(pos==0) {
        ret=0;
        for(int i=0; i<lenAra; i++)
            ret += rec(pos+1, ara[i]);
        return ret;
    }
    if(pos == n)
        return 1;

    if(vis[pos] [prev] == tc)
        return ret;
    ret=0;
    vis[pos] [prev]= tc;

    for(int i=0; i<lenAra; i++)
        if(abs(ara[i] - prev)<3)
            ret += rec(pos+1, ara[i]);

    return ret;
}





int main()
{
//    freopen("out.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(false);

    int t;
    cin>>t;

    for(tc=1; tc<=t; tc++) {
        ull tot =1;
        cin>>lenAra>>n;
        for(int i=0; i<lenAra; i++)  {
            cin>>ara[i];
        }

//        if(ret==0 || ret==tot)
            cout<<"Case "<<tc<<": "<<rec(0, 0)<<endl;
//        else
//            cout<<"Case "<<tc<<": "<<ret<<"/"<<tot<<endl;
    }



    return 0;
}
