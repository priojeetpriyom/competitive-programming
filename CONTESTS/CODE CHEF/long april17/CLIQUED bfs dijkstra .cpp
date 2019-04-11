#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n,k, x, m ,s;
ll cost[100100];

void bfs(vector<pair<int, int> > conn[100100]) {

    queue<int> Q;
    Q.push(s);
    cost[s]=0;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        int len = conn[u].size();

        for(int i=0; i<len; i++) {
            int v = conn[u][i].second;
            int c = conn[u][i].first;
            if(cost[u] + (ll)c < cost[v]) {
                Q.push(v);
                cost[v] = cost[u] + (ll)c;
            }
        }
    }
}

void set_mn() {
    ll mn = 1e15;

    for(int i=1; i<=k; i++) {
        if(cost[i]<mn) mn = cost[i];
    }


    for(int i=1; i<=k; i++) {
        if(mn+x < cost[i])
            cost[i] = mn+x;
    }
}

int main() {
//    freopen("out.txt", "w", stdout);
    for(int i=0; i< 100100; i++) cost[i] = 1e15;
    int t;
    cin>>t;
    for(int tc=1; tc<=t; tc++) {
        vector<pair<int, int> > conn[100100];
        cin>>n>>k>>x>>m>>s;
        int u, v, c;
        for(int i=0; i<m; i++) {
            scanf("%d %d %d",&u, &v, &c);
            conn[u].push_back(make_pair(c, v));
            conn[v].push_back(make_pair(c, u));
        }

        if(s<=k) {
            for(int i=1; i<=k; i++) {
                if(i!=s)
                    conn[s].push_back(make_pair(x, i));
            }
        }

        bfs(conn);

        set_mn();

        for(int i=1; i<=n; i++) {
            printf("%lld", cost[i]);
            if(i!=n) printf(" ");
            cost[i] = 1e15;
        }
        printf("\n");
    }


    return 0;
}
