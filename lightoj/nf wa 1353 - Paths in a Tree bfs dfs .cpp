#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

//int kk[111];
int vis[20100];
int par[20100];

vector<int> conn [20100];

//
void dfs(int u, int par) {
//    printf("u %d\n", u);
    int len = conn[u].size();
    vis[u]++;
//    printf("len %d\n");
//    int ans=0;
    for(int i=0; i<len; i++) {
        if(vis[ conn[u][i] ] != par) {
            dfs(conn[u][i], u);
        }
    }
//    return 0;
//    return ans+ max( (int)conn[u].size()-1 , 0);
}
    int t, n=0, u, v;

int calc() {
    int ans=0;

    vector<int > vec;
    int x=0;
    for(int i=0; i<n; i++) {
        vec.push_back(i);
        if( par[i]== -1) {
            swap(vec[i], vec[x++]);
//            printf("root %d\n", i);
        }
    }


    int len = vec.size();
//    printf("len_vec %d\n", len);
    for(int i=0; i<len; i++) {
//        if(!conn[i].size())
//        {
            if(!vis[vec[i] ])
                {
//            printf("leaf_u %d\n", vec[i]);
                    ans ++;
                    dfs(vec[i], -1);
                }
        }
//        printf("ans after dfs %d\n", ans);

    for(int i=0; i<n; i++) ans+= max( (int)conn[i].size()- vis[i], 0);

    return ans;
}


int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(par, -1, sizeof par);

    scanf("%d", &t);

    for(int tc=1; tc<=t; tc++) {
        for(int i=0; i<=n; i++) {
            vis[i]=0;
            conn[i].clear();
        par[i]= -1;
        }
        scanf("%d", &n);



        for(int i=1; i<n; i++) {
            scanf("%d %d",&u, &v);
            par[u] = v;
            conn[v].push_back(u);
//            par[v]++;
        }

        printf("Case %d: %d\n",tc, calc());



    }

    return 0;

}
