#include <bits/stdc++.h>

using namespace std;
typedef long long ll;





int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, int>mp;
    int n,k;
    cin>>n>>k;

    string s;
    cin>>s;
    int cnt=0;
    for(int i=0; i<s.size(); i++)
        {
            mp[s[i] ]++;
            cnt = max(cnt, mp[s[i] ]);
        }
//        cout<<mp['a']<<endl;


        if(cnt<= k) {
            cout<<"YES"<<endl;
        } else cout<<"NO"<<endl;


    return 0;
}


