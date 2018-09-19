///
///

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 1010




int main()
{
//    cout<<-13%5;
//    freopen("out.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    ios_base::sync_with_stdio(false);
//    cin.tie(false);
    int n=5, x, ans;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin>>x;
            if(x) {
                cout<<abs(i-3)+abs(j-3)<<endl;
            }
        }
    }



    return 0;
}

