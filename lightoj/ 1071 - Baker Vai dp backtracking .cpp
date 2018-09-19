#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 105


int dp[MX] [MX] [MX];
int vis[MX] [MX][MX];
int grid[MX] [MX];
int ncr[MX][MX];
int n,m;

int tc;



int rec(int r1, int c1, int r2) {
//    if(n==1)
//    return 1;

    if(r1>n || r2>n)
        return -1e9;

    if(r1==r2)
        return -1e9;
    int c2= r1+c1-r2;
//    printf("r1 %d c1 %d r2 %d c2 %d\n", r1, c1, r2, c2);
    if(c1>m || c2>m)
        return -1e9;

    if(r1==n && c1==m-1 && r2==n-1 && c2==m)
        return grid[r1][c1]+grid[r2][c2];
    int &ret = dp[r1][c1][r2];
    int &v = vis[r1][c1][r2];

    if(v==tc)
        return ret;
    v=tc;
    ret=0;

    ret = max(ret, rec(r1+1, c1, r2+1));
    ret = max(ret, rec(r1, c1+1, r2));
    ret = max(ret, rec(r1+1, c1, r2));
    ret = max(ret, rec(r1, c1+1, r2+1));

    ret+= grid[r1][c1] + grid[r2][c2];

    return ret;

}

int main()
{

//    process[0]= {1,2,3};

//    cout<<process[0].id<<" "<<process[0].at<<" "<<process[0].bt<<endl;
    int t;

    scanf("%d", &t);
//    memset(ncr, -1, sizeof ncr);
    memset(dp, -1, sizeof dp);


    for( tc=1; tc<=t; tc++) {
//        int n;
        scanf("%d %d", &n, &m);

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                scanf("%d", &grid[i][j]);
            }
        }

        printf("Case %d: %d\n", tc, rec(2,1,1)+grid[1][1]+grid[n][m]);

    }


    return 0;
}
