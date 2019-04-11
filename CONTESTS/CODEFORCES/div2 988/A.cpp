#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100


map<int, int> mp;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n, k;
    cin>>n>>k;

    int x;

    for(int i=0; i<n; i++)
    {
        cin>>x;
        mp[x] = i+1;

    }

    if(mp.size()<k)
    {

        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    int cnt=0;
    for(auto i: mp)
    {
        cout<<i.second<<" ";
        cnt++;
        if(cnt==k) break;
    }
    cout<<endl;


    return 0;
}


