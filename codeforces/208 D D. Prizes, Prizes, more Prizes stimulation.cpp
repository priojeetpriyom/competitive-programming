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

    vector<pair<ll,ll> > vec(5);

    int n;

    cin>>n;

    ll ans[55] = {0}, inp[55];


    for(int i=0; i<n; i++) {
        cin>>inp[i];
    }
    ll x;
    for(int i=0; i<5; i++) {
        cin>>x;
        vec[i] = {x, i};
    }
    sort(vec.begin(), vec.end());

    ll left=0;

    for(int i=0; i<n; i++) {
        left+= inp[i];
        for(int j = 4; j>=0; j--) {
            if(!left)
                break;
            ans[vec[j].second] += (left/vec[j].first);
            left %= vec[j].first;
        }
    }
    for(int i=0; i<5; i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl<<left<<endl;


    return 0;
}
