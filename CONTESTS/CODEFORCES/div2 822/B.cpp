#include <bits/stdc++.h>

using namespace std;
typedef long long ll;





int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    string t,s;
    int lens, lent;
    cin>>lens>> lent;
    cin>>s>>t;


    int mn = 1e9, mn_pos=0;
    for(int i=0; i<=t.size()-s.size(); i++) {
        int cnt=0;
        for(int j=i; j< i+s.size(); j++) {
            if(s[j-i] != t[j] ) cnt++;
        }

        if(cnt<mn) {
            mn = cnt;
            mn_pos = i;
        }
    }


    cout<<mn<<endl;

    for(int i = mn_pos; i< mn_pos+s.size(); i++) {
        if(s[i-mn_pos] != t[i]) cout<< (i-mn_pos+1)<<" ";
     }
    if(mn>0) cout<<endl;





    return 0;
}


