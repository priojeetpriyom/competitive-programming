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

    int n,m;
    cin>>n>>m;
    if(n>30) {
        cout<<m<<endl;
        return 0;
    }
    int pw=1;
    for(int i=1; i<=n; i++) {
        pw*=2;
    }

    cout<<m%pw<<endl;




    return 0;
}


