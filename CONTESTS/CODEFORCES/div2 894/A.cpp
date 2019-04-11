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

    string s;
    cin>>s;
    int ans=0;
    int len = s.size();
    for(int i=0; i<len; i++) {
        if(s[i]=='Q') {
            for(int j= i+1; j<len; j++) {
                if(s[j] =='A') {
                    for(int k=j+1;k<len; k++) {
                        if(s[k]=='Q')
                            ans++;
                    }
                }
            }
        }
    }

    cout<<ans<<endl;



    return 0;
}


