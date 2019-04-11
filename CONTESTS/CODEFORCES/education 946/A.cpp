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


    int n;
    cin>>n;

    int sum=0;
    while(n--)
    {
        int x;
        cin>>x;
        sum+= abs(x);
    }

    cout<<sum<<endl;


    return 0;
}


