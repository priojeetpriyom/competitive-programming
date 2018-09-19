
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int tc=1, dp[101][101], n1, n2,visited[101] [101], ara1[101], ara2[101];

int rec(int i, int j) {
    if(i==n1 || j==n2) return 0;

    int &vis = visited[i][j], &ret = dp[i] [j];
    if(vis == tc) return ret;
    vis = tc;

    if(ara1[i] == ara2[j]) ret = rec(i+1, j+1)+1;
    else {
        ret = max(rec(i+1, j), rec(i, j+1));
    }

    return ret;
}

int main() {
//    freopen("out.txt", "w", stdout);

    while(scanf("%d %d",&n1, &n2 )==2 && (n1 || n2)) {
        for(int i=0; i<n1; i++)
            scanf("%d", &ara1[i]);
        for(int i=0; i<n2; i++)
            scanf("%d", &ara2[i]);

        printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",tc, rec(0,0)); //used logest common subsequnce algo
        tc++;
    }

    return 0;
}

