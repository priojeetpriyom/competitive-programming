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

    int cnt=0;
    for(int i=1; i<n; i++)
        if(n%i==0)
            cnt++;

    cout<<min(cnt, n-1)<<endl;



    return 0;
}


