#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;


string s;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--) {
        cin>>s;
        int len = s.size();
        int vis[100];
        memset(vis, 0, sizeof vis);

        for(int i=0; i<len; i++)
            vis[s[i]-'0' ]++;

        string ans;
        for(int i=65; i<=90; i++) {
            int x = i %10;
            int y = i/10;
            if(x==y)
            {
                if(vis[x]>1)
                    ans+= (char) i;
            }

            else if(vis[y]&&vis[x]) {
                ans+= (char) i;
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
