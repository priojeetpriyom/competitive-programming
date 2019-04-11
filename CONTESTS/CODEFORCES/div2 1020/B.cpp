#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100




int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int ara[1011];

    int n;

    cin>>n;

    for(int i=1; i<=n; i++) {
        cin>>ara[i];
    }
    int vis[1011];
    for(int i=1; i<=n; i++) {
        memset(vis, 0, sizeof vis);
        int j = i;
        while(!vis[j]) {
            vis[j]=1;
            j = ara[j];
        }

        cout<<j<<" ";
    }
    cout<<endl;



    return 0;
}


