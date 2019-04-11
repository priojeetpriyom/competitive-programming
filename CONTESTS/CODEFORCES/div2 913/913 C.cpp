#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 44

double cost[MX];
vector<pair<double, int>>vec;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, l;
    cin>>n>>l;

    for(int i=0; i<n; i++) {
        cin>>cost[i];
    }

    double pw=1;
    ll ara_pw[44];
//    ara_pw[0]=1;
    for(int i=0; i<n; i++) {
        vec.push_back(make_pair(cost[i]/pw, i));
        ara_pw[i] = pw;
        pw*=2;
    }
    sort(vec.begin(), vec.end());

    int i = vec[0].second;
    ll div  = (l/ara_pw[i]);
    ll ans = div *cost[i] ;

    ll rem = l%ara_pw[i-1];

    ll temp, mn;
    while(rem>0) {
        for(int i=0; i<vec.size(); i++) {
            if(cost[vec[i].)
        }
    }

    return 0;
}


