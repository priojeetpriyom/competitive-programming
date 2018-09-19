#include<bits/stdc++.h>
using namespace std;

int n;
int ara[101] [101], dp[101] [101];

int rec(int row, int col) {
    if(row>= n)
        return 0;

    int& ret = dp[row] [col];

    if(ret != -1)
        return ret;

    int down = rec(row+1, col)+ara[row] [col];
    int right = rec(row+1, col+1) +ara[row] [col];
//    printf("row %d col %d ara %d down %d right %d\n", row, col, ara[row] [col], down, right);
    return ret = max(down, right);

}

int main()
{
//    freopen("myOut.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--) {
        cin>>n;
        memset(dp, -1, sizeof dp);
        memset(ara, 0, sizeof ara);
        for(int i=0; i<n; i++) {
            for(int j=0; j<=i; j++) {
                scanf("%d", &ara[i] [j]);
            }
        }
        cout<<rec(0,0)<<endl;

    }
    return 0;

}


