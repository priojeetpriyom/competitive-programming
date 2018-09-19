#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<int> conn[100100];
int dp[100100] [2];

int rec(int u, int prev, int par) {


    int &ret = dp[u] [prev];
    if(ret!= -1) return ret;

    int len = conn[u].size();
    int x=0, y=0;
    if(!prev) y =INT_MAX;
    for(int i=0; i<len; i++) {
        int v= conn[u][i];
        if(v!= par) {
             x+= rec(v, 1, u);
            if(prev) y+= rec(v, 0, u);
        }
    }
    return ret = min(x+1, y);
}

int main()
{
    memset(dp, -1, sizeof dp);

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n;
    cin>>n;
    int u,v;
    for(int i=1; i<n; i++)
    {
        scanf("%d %d", &u, &v);
        conn[u].push_back(v);
        conn[v].push_back(u);
    }
    cout<<rec(1, 1, 0);
    return 0;
}





