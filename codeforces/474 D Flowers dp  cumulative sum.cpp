#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define MX 100100
#define modSQ 101123136
#define ll long long


ll dp[MX];


ll ara[MX], k;

ll rec(int left) {
    if(!left)
        return 1;
    if(left<0)
        return -INT_MAX;

    ll & ret = dp[left];
    if(~ret )
        return ret;

    ret = max(0LL, rec(left-1)) + max(0LL, rec(left-k));
    if(ret>=mod)
        ret%=mod;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(false);
//    process[0]= {1,2,3};

//    cout<<process[0].id<<" "<<process[0].at<<" "<<process[0].bt<<endl;
    int t;
    cin>>t>>k;


        memset(dp, -1, sizeof dp);
    for(int i=1; i<=100000; i++) {
//        printf("dp_%d: %lld\n", i, rec(i));
        ara[i] = ara[i-1] + rec(i);
    }
//    for(int i=1; i<=10; i++) {
//        printf("ara_%d: %lld\n", i, ara[i]);
//    }
//    memset(ncr, -1, sizeof ncr);
    for(int tc=1; tc<=t; tc++) {

        int a, b;

        cin>>a>>b;

        cout<<(ara[b]-ara[a-1]+mod)%mod<<endl;


    }


    return 0;
}
