#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


vector<int> conn[300010];

int vis[300010];
int cost[300010];

int mx = -2e9;
int vv=1;

void get_cost(int u, int depth=0)
{
    if(cost[u]+depth > mx) mx = cost[u]+depth;
    vis[u] =vv;
    if(depth==1)
    {
        return;
    }
    int len = conn[u].size();
    for(int i=0; i<len; i++)
    {
        if(vis[conn[u][i]] != vv)
            get_cost(conn[u][i], depth+1);
    }
//    vis[u]= 0;
}

bool r_cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first> b.first;
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n;
    cin>>n;
    int u,v;
//    map<int, bool> mp_u, mp_v;
    vector<pair<int, int> > vec;
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &cost[i]);
        vec.push_back(make_pair((int)cost[i], i));
    }
    sort(vec.begin(), vec.end(), r_cmp);

//    for(int i=0; i<vec.size(); i++)
//        printf("cst %d u %d\n", vec[i].first, vec[i].second);

    for(int i=1; i<n; i++)
    {
        scanf("%d %d", &u, &v);
//        mp_u[u] = v;
//        mp_v[v] = u;
        conn[u].push_back(v);
        conn[v].push_back(u);
    }

    //
//    for(int i=1; i<=n; i++)
//        rec(i, 0, -1);
////    rec(1, 0, -1);
////    for(int i=1; i<=n; i++)
////        printf("%d ", dp[i] [0]);
//    ll mx = -3e9, mx_idx=1;
//
//    for(int i=1; i<=n; i++) {
//        if(cost[i]+dp[i][0] > mx) {
//            mx = cost[i] + dp[i][0];
//            mx_idx = i;
//        } else if(cost[i]+dp[i][0] == mx) {
//            if(cost[i] > cost[mx_idx]) {
//                mx = cost[i] + dp[i][0];
//                mx_idx = i;
//            } else if(cost[i] == cost[mx_idx] && conn[i].size()> conn[mx_idx].size()) {
//                mx = cost[i] + dp[i][0];
//                mx_idx = i;
//            }
//        }
//    }
////    printf("mx_idx %d\n", mx_idx);
////    vis[mx_idx]= 1;
////    fire(mx_idx, 0, 0);
//    dfs(mx_idx);
//}

    int ans= 2e9;
    int len = vec.size();
    for(int i=1; i<=n; i++)
    {
        mx = -2e9;
        vis[i] = vv;
        get_cost(i);
//        printf("i %d mx after dfs %d v %d\n",i, mx, vv);
        for(int i=0; i<len; i++)
        {
            int cst = vec[i].first, u = vec[i].second;
            if(vis[u]!=vv)
            {
//                printf("u %d cst %d vis[u] %d\n", u, cst+2, vis[u]);
                mx = max(mx, cst+2);
                break;
            }
        }

        ans = min(ans, mx);




        vv++;
//        if(x > mx) {
//            mx = x;
//
//        }
    }
    cout<<ans;
    return 0;
}


