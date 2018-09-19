#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100
#define double long double
#define mod 1000000007
#define mod2 1000000009


ll hasht, pw, base=257;
int n, cnt[MX], dp[MX];
vector<int> vec;
set<int> divs[MX];
//unordered_set<int> sset;
//int called=0;
//int dfs(int u) {
////    cout<<"u "<<u<<endl;
//    called++;
////    cout<<"called "<<called<<endl;
////    if(vis[u])
////        return 0;
////    vis[u]=1;
//    if(~dp[u])
//        return dp[u];
//    int ret =0;
//    ret=0;
////    for (int i = 0; i < divs[u].size(); ++i) {
////        int d = divs[u][i];
////
////        for(int j=0; j<conn[d].size(); j++) {
////            if(vis[conn[d][j] ])
////                continue;
////            if(!vis[conn[d][j] ]) {
////                ret = max(ret, dfs(conn[d][j]) +cnt[u]);
////            }
////        }
////        conn[d].clear();
////    }
////    divs[u].clear();
//    for(int it: sset){
//        if(it!= u &&  vis[it]==0 && __gcd(u, it)>1){
//            cout<<"u "<<u<<" it "<<it<<" _gcd "<<__gcd(u, it)<<endl;
//            getchar();
//            vis[it]=1;
//            sset.erase(sset.find(it));
//            ret = max(ret, dfs(it)+ cnt[u]);
//        }
//    }
////    vis[u]=0;
//    return dp[u] = ret;
//}


int main()
{

    double time = clock();
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    freopen("input.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

//    memset(dp, -1, sizeof dp);


//    cout<<1e5<<endl;
//
//    for(int i=1; i<=1e5; i++)
//        cout<<i<<" ";
//    cout<<endl;


    cin>>n;
    int x;

    for(int i=0; i<n; i++) {
        cin>>x;
        cnt[x]++;
//        if(cnt[x]==1)
//            sset.insert(x);
    }
    n = vec.size();
//    cout<<"input taken"
    int root = sqrt(1e5)+1;
    for(int i=2; i<root; i++) {
//        if(!vis[i]) {
            for(int j = i+i; j<=1e5; j+=i) {
                if(cnt[j]){
                    divs[j].insert(i);
                    if(i!=j/i && j/i>1)
                        divs[j].insert(j/i);
                }
            }
//        }
    }
//    cout<<(clock()-time)/CLOCKS_PER_SEC<<endl;

//    for(int i=1; i<=1e5; i++) {
//        if(cnt[i]) {
//            cout<<"i "<<i<<" : ";
//            for(int d: divs[i])
//                cout<<d<<" ";
//            cout<<endl;
//        }
//    }

//    if(true)
//        return 0;
    int ans=1;
//    memset(dp, -1, sizeof dp);
//    memset(vis, 0, sizeof vis);
    for(int i=1; i<=1e5; i++) {
        if(!cnt[i])
            continue;
        dp[i]=1;
        for(int d: divs[i]) {
//            cout<<"d "<<d<<" dp[d] "<<dp[d]<<endl;
            dp[i] = max(dp[i], dp[d]+1);
        }
        for(int d: divs[i])
            dp[d] = dp[i];
//            cout<<"i "<<i<<" dp[i] "<<dp[i]<<endl;
        ans = max(ans, dp[i]);
    }
//    cout<<(clock()-time)/CLOCKS_PER_SEC<<endl;


//    if(true)
//        return 0;

//    cout<<"aise"<<endl;

    cout<<ans<<endl;


//    cout<<(clock()-time)/CLOCKS_PER_SEC<<endl;

    return 0;
}
