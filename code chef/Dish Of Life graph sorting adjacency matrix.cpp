#include <bits/stdc++.h>

using namespace std;
int n,k, vis[100010], cnt_vis, tc;

bool make_visited(int u, vector<int> conn[100010]) {

//    for(int i=1; i<=n; i++) {
//        for(int j=0;  j<conn[i].size(); j++) {
//            printf("%d ", conn[i][j]);
//        }
//        printf("\n");
//    }

    int len = conn[u].size(), con=0;

    for(int i=0; i<len; i++) {
//        printf("conn[u][i] %d tc %d vis[conn[u][i]] %d\n", conn[u][i], tc, vis[conn[u][i]]);
        if(vis[conn[u][i] ] != tc) {
            vis[conn[u][i]]=tc;
            cnt_vis++;
            con=1;
        }
    }
    return con;
}


int main() {
//    freopen("out.txt", "w", stdout);
    int t;
    cin>>t;

    for(tc=1; tc<=t; tc++) {
        vector<int> conn[100100];
        vector<pair<int, int> > vec;
        cin>>n>>k;
        for(int i=1; i<=n; i++) {
            int x, u;
            scanf("%d", &x);
            vec.push_back(make_pair(x, i));
            while(x--){
                scanf("%d", &u);
                conn[i].push_back(u);
            }
        }
        sort(vec.begin(), vec.end());
        int all = 1;
        cnt_vis=0;
        for(int i=vec.size()-1; i>=0; i--) {
            if(!make_visited(vec[i].second, conn))
                all=0;
            if(cnt_vis == k) {
                if(i!=0) all =0;
                break;
            }
        }
//        printf("cnt_vis %d\n", cnt_vis);
        if(cnt_vis ==k) {
            if(all) printf("all\n");
            else  printf("some\n");
        } else
            printf("sad\n");
    }


    return 0;
}

