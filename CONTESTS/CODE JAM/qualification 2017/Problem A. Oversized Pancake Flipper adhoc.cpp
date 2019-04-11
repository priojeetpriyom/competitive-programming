#include <bits/stdc++.h>
//#include <iostream>
using namespace std;
typedef long long ll;

bool valid(string s, int len) {
    for(int i=0; i<len; i++) {
        if(s[i]== '-')
            return false;
    }
    return true;
}


int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    cin>>t;
    for(int tc=1; tc<=t; tc++)
    {
        int k;
        string s;
        cin>>s>>k;

        printf("Case #%d: ",tc);
        int cnt=0;
        for(int i=0; i<=s.size()-k; i++) {
            if(s[i] == '-') {
                for(int j =0; j<k ;j++) {
                    if(s[j+i]=='+') s[j+i] ='-';
                    else s[j+i] = '+';
                }
                cnt++;
            }
        }

        if(valid(s, s.size())) {
            cout<<cnt<<endl;
        } else cout<<"IMPOSSIBLE"<<endl;

    }

    return 0;
}




