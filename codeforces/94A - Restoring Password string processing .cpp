#include <bits/stdc++.h>
using namespace std;

vector<int> vec;
int main()
{
//    freopen("myOut.txt", "w", stdout);

    string str,s[11], ans;
    cin>>str;
    for(int i=0; i<10; i++)
        cin>>s[i];

    for(int i=0; i<80; i+=10) {
        for(int j=0; j<10; j++) {
            if(str.substr(i, 10) == s[j]) {
                ans+= (j+'0');
                break;
            }
        }
    }
    cout<<ans;
}



