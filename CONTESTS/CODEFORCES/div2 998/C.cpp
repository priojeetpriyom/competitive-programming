#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100

string s;
ll x, y, ans;


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n>>x>>y;
    cin>>s;

    if(y<=x) {

        for(int i=0; i<n; i++) {
            if(s[i] == '0')
            {
                ans+= y;
                while(s[i]=='0'&&i<n)
                    i++;
            }
        }

        cout<<ans<<endl;
        return 0;

    }

    int pos = 0;
    bool zero=false;
    while(s[pos]=='1'&& pos<n) {
        pos++;
    }
    while(s[pos]=='0'&& pos<n) {
        zero=true;
        pos++;
    }
    while(pos<n) {
        if(s[pos]=='1')
        {
            pos++;
            continue;
        }
        zero = true;
        while(s[pos] =='0' && pos<n)
            pos++;

//        ans+= y;
//        if(pos == n) {
//
//            break;
//        }
//
//
//        while(s[pos] =='1' && pos<n)
//            pos++;
//
//        if(pos == n) {
//            break;
//        }

        ans+= x;

//        while(s[pos] =='0' && pos<n)
//            pos++;

    }

    if(zero)
        ans+=y;

    cout<<ans<<endl;


    return 0;
}
