#include <bits/stdc++.h>
//#include <iostream>
using namespace std;
typedef long long ll;

string calc(string s) {

    for(int i=0; i<s.size()-1; i++) {
        if(s[i]>s[i+1]) {
//            if(s[i]=='0') {
                int j = i;
                while(j!=0 && (s[j]-1 < s[j-1])) {
                    s[j] = '9';
                    j--;
                }
                s[j] = s[j] -1;
//            } else {
//
//            }
            for( i =i+1; i<s.size(); i++)
                s[i] = '9';
            break;
        }
    }
    if(s[0]=='0') return s.substr(1);
    return s;
}


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int t;
    cin>>t;
    string s;
    for(int tc=1; tc<=t; tc++)
    {
        cin>>s;

        printf("Case #%d: %s\n",tc, calc(s).c_str());

    }

    return 0;
}





