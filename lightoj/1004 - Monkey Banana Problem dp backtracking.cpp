#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int grid[222][222], dp[222][222];
int n, lim;

int rec(int row, int col) {
    if(!grid[row] [col])
        return 0;
    if(row == lim && col == n) {
        return grid[row] [col];
    }

    int &ret = dp[row] [col];

    if(ret != -1)
        return ret;

    ret= max(ret, rec(row+1, col+1)+grid[row] [col]);
    ret= max(ret, rec(row+1, col-1)+grid[row] [col] );
    return ret;
}

int main()
{
//    freopen("out.txt", "w", stdout);

    int t;
    cin>>t;

    for(int tc=1; tc<=t; tc++) {
        scanf("%d", &n);
        int x = n;
        for(int i=1; i<=n; i++) {
            for(int j = n-i+1; j<= x; j+=2) {
                scanf("%d", &grid[i][j]);
            }
            x+=1;
        }
        x-=1;
        for(int i=n+1; i<n+n; i++) {
            for(int j = i-n+1; j<= x; j+=2) {
                scanf("%d", &grid[i][j]);
            }
            x-=1;
        }


//        for(int i=1; i< n+n; i++) {
//            for(int j=1; j<n+n; j++)
//                printf("%d ",grid[i][j]);
//            printf("\n");
//        }

        lim = n+n-1;

        memset(dp, -1, sizeof dp);
        printf("Case %d: %d\n", tc, rec(1,n));
        memset(grid, 0, sizeof grid);

    }



    return 0;
}




