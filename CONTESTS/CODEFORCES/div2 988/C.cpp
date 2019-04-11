#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 200100


map<ll, pair<int, int> > mp;
vector<int> vec[MX];

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int k, n, x;
    cin>>k;

    for(int i=1; i<=k; i++) {
        cin>>n;
        ll sum=0;
        vec[i].push_back(-1e9);
        for(int j=1; j<=n; j++) {
            cin>>x;
            vec[i].push_back(x);
            sum+=x;
        }
        for(int j=1; j<=n; j++) {
                ll diff = sum - vec[i][j];
            if(mp.find(diff)!= mp.end() && mp[diff].first!=i ) {
                cout<<"YES"<<endl;
                cout<<i<<" "<<j<<endl;
                cout<<mp[diff].first<<" "<<mp[diff].second<<endl;
                return 0;
            }
            mp[diff] = {i, j};

        }
    }

    cout<<"NO"<<endl;

    return 0;
}


