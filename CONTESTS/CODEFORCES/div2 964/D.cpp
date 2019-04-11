#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 200100

vector<int> conn[MX];
int done[MX];
int degree[MX];
queue<int> odds;
vector<int>ans;

void process(int idx) {

    int len = conn[idx].size();
    done[idx]=1;
    ans.push_back(idx);

    for(int i=0; i<len; i++) {
     int v = conn[idx] [i];
        if(!done[v]) {
            degree[v]--;
            if(degree[v]==0) {
//                printf("for u %d empty %d\n", idx, v);
                ans.push_back(v);
                done[v]=1;
            } else if(degree[v]%2==1) {
                odds.push(v);
            }
        }
    }


}


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    int n;
    scanf("%d", &n);

    int x;
    for(int i=1; i<=n; i++) {
        scanf("%d", &x);
        if(x) {
            conn[x].push_back(i);
            conn[i].push_back(x);
            degree[i]++;
            degree[x]++;
        }
    }
//            for(int i=1; i<=n; i++)
//                printf("%d ", degree[i]);
//            printf("\n");

        queue<int> odds;
        for(int i=1; i<=n; i++) {
            if(degree[i]&1)
                odds.push(i);
        }


        while(!odds.empty()) {
            int cur = odds.front();
            odds.pop();
            if(degree[cur]%2==0 || done[cur]) {
                continue;
            }
            int len =conn[cur].size();
            for(int i=0; i<len; i++) {
                if(!done[ conn[cur] [i]] && degree[conn[cur][i] ] %2==0) {
                    process( conn[cur] [i] );
//                    printf("cur %d idx %d\n", cur, conn[cur] [i]);
//                    for(int i=1; i<=n; i++)
//                        printf("%d ", degree[i]);
//                    printf("\n");
                }

            }
        }


    int cnt=0;
    for(int i=1; i<=n; i++) {
        if(done[i])
            cnt++;
        else if(degree[i]%2==0) {
            process(i);
            cnt++;
        }

    }


    if(cnt==n) {
        printf("YES\n");
        for(int i=0; i<n; i++)
            printf("%d\n", ans[i]);
    } else
        printf("NO\n");


    return 0;
}


