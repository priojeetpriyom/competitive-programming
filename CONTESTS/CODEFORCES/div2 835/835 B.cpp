#include <bits/stdc++.h>

using namespace std;
typedef long long ll;




    string s;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll k, cnt=0;
    cin>>k>>s;

    sort(s.begin(), s.end());
    int len = s.size();
    for(int i=0; i<len; i++) {
        cnt+=(s[i]-'0');
    }
    int ans=0;
    for(int i=0; cnt<k; i++) {
        ans++;
        cnt+= (9 - (s[i] - '0') );
    }


    cout<<ans<<endl;


    return 0;
}


