#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


string s;
int vis[500];

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int len, k;

    cin>>len>>k;

    cin>>s;
    int last[500];


    for(int i=0; i<len; i++)
        last[s[i] ] = i;
    int cnt=0;
    bool yes = false;
    for(int i=0; i<len; i++) {
        if(!vis[s[i] ]) {
            cnt++;
            if(cnt>k) {
                yes = true;
                break;
            }
            vis[s[i] ] =1;
        }
        if(last[s[i] ] == i) cnt--;
    }

    if(yes) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}


