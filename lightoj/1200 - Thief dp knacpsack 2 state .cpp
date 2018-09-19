#include<bits/stdc++.h>
using namespace std;
#define mod 10056
#define MX 10003
#define modSQ 101123136
#define ll long long


//ll dp[MX];
int dp[105][MX];
int weight[105], price[105], n;

ll rec(int pos, int left) {
    if(left<0)
        return -1e8;
    if(pos == n)
        return 0;

    int & ret = dp[pos] [left];
    if(~ret)
        return ret;
    ret = max(rec(pos, left - weight[pos])+price[pos], rec(pos+1, left));
//    printf("n %d ret %d\n", n, ret);
    return ret;

}

int main()
{

//    process[0]= {1,2,3};

//    cout<<process[0].id<<" "<<process[0].at<<" "<<process[0].bt<<endl;
    int t;

    scanf("%d", &t);
//    memset(ncr, -1, sizeof ncr);
    for(int tc=1; tc<=t; tc++) {
        memset(dp, -1, sizeof dp);
        int left, c;
        scanf("%d %d", &n, &left);

        for(int i=0; i<n; i++) {
            scanf("%d %d %d", &price[i], &c, &weight[i]);
            left-= (c*weight[i]);
        }
        int ans =0;
        printf("Case %d: ", tc);
        if(left<0) {
            printf("Impossible\n");
        } else
            printf("%d\n", rec(0, left));


    }


    return 0;
}
