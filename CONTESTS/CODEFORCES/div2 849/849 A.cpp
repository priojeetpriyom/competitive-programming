#include <bits/stdc++.h>

using namespace std;
typedef long long ll;





int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int ara[111];

    int n;
    cin>>n;

    for(int i=1; i<=n; i++)
        cin>>ara[i];

    if ((n&1) && (ara[1]&1) && (ara[n]&1)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;


    return 0;
}


