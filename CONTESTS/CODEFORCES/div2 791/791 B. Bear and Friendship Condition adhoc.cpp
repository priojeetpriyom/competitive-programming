#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int par[151000], cnt[151000];
vector<int> connection[151000];
int find_par(int node) {
//   if(node == par[node])
//    printf("node %d par %d\n", node, par[node]);
//    getchar();
    if(node == par[node]) return node;

    return par[node] = find_par(par[node]);
}

void dsu(int v, int u) {
//    printf("finding for u\n");
    int x = find_par(u);
//    printf("finding for v\n");
    par[x] = find_par(v);
//    printf("finding for u2\n");
    find_par(u);
}




int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int n,m;
    for(int i=0; i<150111; i++)
        par[i] = i;
    cin>>n>>m;
    int u,v;

    for(int i=0; i<m; i++) {
        scanf("%d %d", &u, &v);
        dsu(u,v);
        cnt[u]++;
        cnt[v]++;
    }
    map<int, int> mp;
    for(int i=1; i<=n; i++) {
        mp[par[i]]++;
        connection[par[i]].push_back(i);
    }

    map<int, int>::iterator it;

    for(it = mp.begin(); it!= mp.end(); it++) {
        if(it->second>1) {
            for(int i=0; i<connection[it->first].size(); i++) {
                if(cnt[connection[it->first] [i]] != (it->second -1)) {
                    printf("NO\n");
                    return 0;
                }
            }
        }
    }
    printf("YES\n");

    return 0;
}


