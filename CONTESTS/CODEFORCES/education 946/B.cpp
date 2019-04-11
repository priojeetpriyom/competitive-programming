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


    ll n, m;

    cin>>n>>m;

    while(n>0 && m>0) {
        if(n>=m*2)
            n= n%(m*2);
        else if(m>= n*2)
            m= m% (n*2);
        else
            break;
    }

    cout<<n<<" "<<m<<endl;


    return 0;
}


