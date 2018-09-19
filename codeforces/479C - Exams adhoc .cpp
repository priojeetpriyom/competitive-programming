#include <bits/stdc++.h>
using namespace std;

#define MX 110

vector<pair<int, int> > vec;

int main() {
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        int u,v;
        cin>>u>>v;
        vec.push_back({u,v});
    }
    sort(vec.begin(), vec.end());
    int mx=0;
    int cur=0;
    for(int i=0; i<n; i++) {
        if(cur > min(vec[i].first, vec[i].second))
            cur= max(vec[i].first, vec[i].second);
        else
            cur = min(vec[i].first, vec[i].second);
        mx = max(mx, cur);
    }

    cout<<mx<<endl;
    return 0;
}


