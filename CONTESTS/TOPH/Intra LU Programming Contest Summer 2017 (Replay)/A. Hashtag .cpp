#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

//#include <stdio.h>
//#include <string.h>
//#define ll long long

string s;
int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    getline(cin, s);
    for(int i=0; i<s.length(); i++) if(s[i]!= ' ') cout<<s[i]; cout<<endl;

    return 0;
}
