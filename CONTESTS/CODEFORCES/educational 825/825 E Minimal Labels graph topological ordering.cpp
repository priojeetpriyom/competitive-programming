#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
int out[100005];
vector<int> in_nodes[100005];

struct cmp{

operator() (pi a, pi b) {
    if(a.first!= b.first) return a.first < b.first;
    return a.second > b.second;
}
};

set<pair<int, int>, cmp > sset;
int ans[100005];
int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin>>n>>m;
    int u,v;
    for(int i=0; i<m; i++) {
        cin>>u>>v;
        out[u]++;
        in_nodes[v].push_back(u);
    }


    for(int i=1; i<=n; i++) {
        sset.insert(make_pair(out[i], i));
    }

    int label = n;
    set<pi, cmp > :: iterator it;
    while(label) {

        int u = (*sset.begin()).second;
        sset.erase(sset.begin());
        ans[u] = label;

        int len = in_nodes[u].size();

        for(int i=0; i<len; i++)
        {
            v = in_nodes[u][i];
            it = sset.find(make_pair(out[v], v));
            out[v]--;
            sset.erase(it);
            sset.insert(make_pair(out[v], v));

        }


        label--;
    }
    cout<<ans[1];
    for(int i=2; i<=n; i++)
        cout<<" "<<ans[i];
    cout<<endl;


    return 0;
}

