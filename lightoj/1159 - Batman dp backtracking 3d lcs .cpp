#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 55

int n, dp[MX][MX][MX];
string a, b, c;
int vis[MX] [MX] [MX], tc;


ull rec(int i, int j, int k) {
    int &ret = dp[i] [j] [k];
    if(i == a.size() || j  == b.size() || k == c.size())
        return 0;

    if(vis[i] [j] [k] == tc)
        return ret;
//    ret=0;
    vis[i] [j] [k]= tc;

    if(a[i] == b[j] && b[j] == c[k])
        ret = rec(i+1, j+1, k+1)+1;
    else
        ret = max(rec(i+1, j, k), max(rec(i, j+1, k), rec(i, j, k+1)));

    return ret;
}





int main()
{
//    freopen("out.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(false);

    int t;
    cin>>t;
    cin.ignore();
    for(tc=1; tc<=t; tc++) {
        cin>>a>>b>>c;
//        cout<<a<<","<<b<<","<<c<<endl;
//        if(ret==0 || ret==tot)
            cout<<"Case "<<tc<<": "<<rec(0, 0, 0)<<endl;
//        else
//            cout<<"Case "<<tc<<": "<<ret<<"/"<<tot<<endl;
    }



    return 0;
}

