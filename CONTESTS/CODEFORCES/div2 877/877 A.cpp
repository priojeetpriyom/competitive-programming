#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MX 55





int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    map<string, int>mp;
    mp["Danil"] = 1;
    mp["Olya"] = 1;
    mp["Slava"] = 1;
    mp["Ann"] = 1;
    mp["Nikita"] = 1;
    int cnt=0;
    string s;
    cin>>s;
    for(int i =0; i<s.size(); i++) {
        for(int j = 1; j<=s.size() - i; j++) {
            if(mp[ s.substr(i, j) ])
                cnt++;
        }
    }

    if(cnt==1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}


