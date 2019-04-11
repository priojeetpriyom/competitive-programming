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
    int ara[1010];
    map<int, int> mp;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>ara[i], mp[ara[i]]=1;

    int gcdd = ara[0];
    for(int i=1; i<n; i++) {
          gcdd = __gcd(gcdd, ara[i]);

    }

    if(gcdd != ara[0]) {
        cout<<-1<<endl;
        return 0;
    }

    cout<<n+n-1<<endl;
    cout<<ara[0];
    for(int i=1; i<n; i++)
        cout<<" "<<ara[i]<<" "<<ara[0];



    return 0;
}


