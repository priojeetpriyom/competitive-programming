
#include <bits/stdc++.h>
using namespace std;
int ans[500], comp[500];

int main()
{
//    freopen("myOut.txt", "w", stdout);
    int len, cnt=INT_MAX,it=0;
    string str = "Bulbasaur", s;
    cin>>s;
    len = s.length();

    for(int i=0; i<len; i++) {
        ans[s[i]]++;
    }

    for(int i=0; i< str.length(); i++)
        comp[str[i]]++;

    for(int i=0; i<500; i++)
    {
        if(comp[i] !=0) {
            cnt = min(cnt, ans[i]/comp[i]);
        }
    }

    cout<<cnt;
    return 0;
}

