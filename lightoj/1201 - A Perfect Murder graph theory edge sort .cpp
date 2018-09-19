#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 55

int n, tc, m;


//vector<int> conn[1010] [1010]; //, cnt[1010];



int main()
{
//    cout<<-13%5;
//    freopen("out.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(false);

    ll t, q;
    cin>>t;
    cin.ignore();
    for(tc=1; tc<=t; tc++) {
//        memset(vis, -1, sizeof vis);
        cin>>n>>m;
        set<int> sset;
        vector<int> conn[1010];
        memset(conn, 0 , sizeof conn);
        int taken[1010] = {0}, cnt [1010] = {0};

        for(int i=1; i<=m; i++) {
            int u, v;
            cin>>u>>v;
//            conn[u][v] = conn[v][u]=1;
            conn[u].push_back(v);
            conn[v].push_back(u);
            cnt[u]++;
            cnt[v]++;
        }

//        for(int i=1; i<=n; i++)
//            sset.insert(cnt[i]);
//
        int ans=0;
//        set<int> :: iterator it;
//        for(it = sset.begin(); it!= sset.end(); it++) {
//            for(int i=1; i<=n; i++) {
//                if(cnt[i]== *it && !taken[i]) {
//                    for(int u = 0; u< conn[i].size(); u++)
//                        taken[ conn[i][u] ]=1;
//                    taken[i]=1;
//                    ans++;
//                }
//            }
//        }


        int node = n;

        while(node>0) {
//            printf("node %d\n", node);
//            for(int i=1; i<=n; i++)
//                printf("%d ", cnt[i]);
//            printf("\n");
//            for(int i=1; i<=n; i++)
//                printf("%d ", taken[i]);
//            printf("\n");
//            getchar();
            for(int i=1; i<=n; i++) {

                if(!taken[i] && cnt[i]<=1) {
                    taken[i]=1;
                    node--;
                    ans++;

                    for(int p=0; p< conn[i].size(); p++) {
                        int &u = conn[i][p];
                        if(taken[u])
                            continue;
                        node--;
                        taken[u]=1;
                        for(int q=0; q< conn[u].size(); q++) {
                            int & v = conn[u][q];
                            cnt[v]--;
                        }
                    }
                }
            }

        }


        cout<<"Case "<<tc<<": "<<ans<<endl;

//        cout<<a<<","<<b<<","<<c<<endl;
//        if(ret==0 || ret==tot)
//        else
//            cout<<"Case "<<tc<<": "<<ret<<"/"<<tot<<endl;
    }



    return 0;
}
