#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, x, y, m;
vector<ll> vec [200100], p;
map<ll, int> mp;


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    cin>>n;

    for(int i=0; i<n; i++) {
        scanf("%I64d", &x);
        p.push_back(x);
        mp[x]+=2;
    }


    for(int i=0; i<n; i++) {
        scanf("%I64d", &x);
        vec[x].push_back(x);
    }


    for(int i=0; i<n; i++) {
        scanf("%I64d", &x);
        vec[x].push_back(x);
    }

    cin>>m;

    while(m--) {
        scanf("%I64d", &x);

        while(mp[ vec[x][0] ]<=0) {
            vec[x].erase(vec[x].begin());
        }

        if(!vec[x].size()) {
            printf("-1 ");
        } else {
            printf("%I64d ", vec[x][0]);
            mp[vec[x][0]]-=2;
            vec[x].erase(vec[x].begin());
        }
    }
        printf("\n");

    return 0;
}


