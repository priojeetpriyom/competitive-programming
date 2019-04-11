#include <bits/stdc++.h>
using namespace std;
string s;
map<int, string> mp;
int main()
{
//    freopen("myOut.txt", "w", stdout);
    int n;
    cin>>n;
    getchar();
    cin>>s;
    int len = s.length();
    int right =1 , left = -1;
    for(int i=0; i<len; i++) {
        if(i==0) {
            mp[0] = s[0];
        }
        else if((len-i)%2 ==0) {
            mp[right++] = s[i];
        } else {
            mp[left--] = s[i];
        }
    }

    std::map<int, string>::iterator it = mp.end();

    for(--it; ; it--)
    {

        cout<<it->second;
        if(it == mp.begin())
            break;
    }

    return 0;
}


