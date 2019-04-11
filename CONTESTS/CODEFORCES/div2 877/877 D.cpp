#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MX 1010

int dp[MX][MX], k;
char grid[MX] [MX];
    int n, m;
int x2, y2;

int rec(int x, int y) {
    if(x==n || y==m) return 1e9;
    if(x==x2 && y==y2) return 0;

    int ret = 1e9;
    for(int i=1; i<=k && i+x < n; i++) {
        if(s[i+x] [y]!= 'x')
        ret = min(ret, rec(x+i, y)+1);
        else break;
    }
    for(int i=1; i<=k && i+x < n; i++) {
        if(s[i+x] [y]!= 'x')
        ret = min(ret, rec(x+i, y)+1);
        else break;
    }
    for(int i=1; i<=k && i+x < n; i++) {
        if(s[i+x] [y]!= 'x')
        ret = min(ret, rec(x+i, y)+1);
        else break;
    }


}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof dp);

    cin>>n>>m;


    for(int i=0; i<n; i++)
        cin>>grid[i];
    int x1, x2;
    cin>>x1>>y1>>x2>>y2;

    cout<<rec(x1-1, y1-1);


    return 0;
}


