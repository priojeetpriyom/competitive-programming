#include <bits/stdc++.h>

using namespace std;
typedef long long ll;





int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    int n;
    cin>>n;
    cin>>s;
    int cnt=0;
    if(s.size()==1) {
        cout<<s<<endl;
        return 0;
    }

    int i=0;

    while(s[i]=='0' && i<n) i++;

    if(i==n) {
        cout<<0<<endl;
        return 0;
    }


    for(; i<s.size(); i++) {
        if(i==0 && s[i]=='0') continue;
        cnt=0;
        while(s[i]=='1' && i<s.size()) cnt++,i++;
        cout<<cnt;
        if(i==n-1 && s[i]=='0') cout<<0;
//        if(cnt)
    }
    cout<<endl;


    return 0;
}


