#include <bits/stdc++.h>

using namespace std;
typedef long long ll;





int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n;
    int cnt=0, mx=0;
    cin>>n;
    n+=n;
    int x=0;
    map<int , int>mp;
    for(int i=0; i<n; i++) {
        cin>>x;
        if(mp.find(x) != mp.end()) {
            mp.erase(mp.find(x));
            cnt--;
        } else {
            mp[x]++;
            cnt++;
            mx = max(mx, cnt);
        }
    }

    cout<<mx;
    return 0;
}


