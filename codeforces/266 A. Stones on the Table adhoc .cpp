#include <bits/stdc++.h>
using namespace std;

int main()

{
    int n;
    cin>>n;
    char s;
    vector<char> str;
    int cnt=0;
    for(int i=0; i<n; i++) {
        cin>>s;
        str.push_back(s);
    }
    for(int i=1; i<n; i++) {
        if(str[i] == str[i-1])
        {
            cnt++;
            str.erase(str.begin() + i);
            i=0;
            n--;
        }
    }
    cout<<cnt;

    return 0;
}


