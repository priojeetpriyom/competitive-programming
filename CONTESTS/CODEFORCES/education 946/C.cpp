#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100




int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;

    cin>>s;
    char ch = 'a';
    for(int i=0; i<s.size(); i++) {
        if(s[i]<=ch)
        {
            s[i] = ch;
            ch++;
        }

        if(ch>'z'){
            cout<<s<<endl;
            return 0;
        }


    }
    cout<<-1<<endl;


    return 0;
}


