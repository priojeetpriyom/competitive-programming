#include<bits/stdc++.h>
using namespace std;
#define mod 10056
#define MX 1003
#define modSQ 101123136
#define ll long long


ll dp[MX];
int ncr[MX][MX];


//int nCr (int n, int r) {
//    if(r==1)
//        return n;
//    if(n==r)
//        return 1;
//
//    int &ret = ncr[n][r];
//    if(~ret)
//        return ret;
//
//
//    ret = nCr(n-1, r-1) + nCr(n-1, r);
//    if(ret>=modSQ)
//        ret%=mod;
//
//    return ret;
//
//
//}



ll rec(int n) {
//    if(n==1)
//    return 1;
    ll & ret = dp[n];
    if(~ret)
        return ret;
    ret=1;
    for(int i=1; i<n; i++) {
//        printf("n %d r %d ncr %d\n",n, i, nCr(n, i));
        ret+= (ncr[n][i] *rec(n-i));
    }
    if(ret>=modSQ)
        ret%=mod;
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
    memset(dp, -1, sizeof dp);

    for(int i=1; i<=1000; i++) {
        ncr[i][i]=1;
        ncr[i][1]=i;
        for(int j=2; j<i; j++)
        {
            ncr[i][j] = ncr[i-1][j-1] + ncr[i-1] [j];
            if(ncr[i][j]>=modSQ)
                ncr[i][j] %=mod;
        }
    }

    for(int tc=1; tc<=t; tc++) {
        int n;
        scanf("%d", &n);

        printf("Case %d: %lld\n", tc, rec(n)%mod);

    }


    return 0;
}
