#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MX 55





int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    cout<<(n/2)*3 + (n&1)<<endl;

    for(int i=2; i<=n; i+=2)
        cout<<i<<" ";
    for(int i=1; i<=n; i+=2)
        cout<<i<<" ";

    for(int i=2; i<=n; i+=2)
        cout<<i<<" ";
    cout<<endl;





    return 0;
}


