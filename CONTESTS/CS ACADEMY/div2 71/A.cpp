#include <bits/stdc++.h>

using namespace std;
typedef long long ll;





int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin>>s;

    int f=0;

    for(auto c:  s) {

        if(c=='A') {
            f++;
        }else
            f=0;
        if(f<2)
            cout<<c;

    }
    cout<<endl;


    return 0;
}


