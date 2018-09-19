#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 15
int ara[100100];

int main()
{
//    cout<<-13%5;
//    freopen("out.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(false);

    string s1, s2;

    cin>>s1>>s2;

    for(int i=0; i<s1.size(); i++) {
        if(toupper(s1[i]) > toupper(s2[i])) return cout<<1<<endl, 0;
        else if(toupper(s1[i]) < toupper(s2[i])) return cout<<-1<<endl, 0;
    }
    cout<<0<<endl;

    return 0;
}


