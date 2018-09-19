#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, k, dp[501+5] [501+5];
int ara[501+5], one[505], zero[505];

int calc_unhappiness(int pos, int lim) {
//    int onee=0, zeroo=0;
//    for(int i = pos; i<= lim; i++) {
//        if(ara[i]) onee++;
//        else zeroo++;
//    }
//    return onee * zeroo;
    return (one[lim] - one[pos-1]) * (zero[lim]-zero[pos-1]);
}

int rec(int pos_n, int pos_k) {
//    printf("pos_n %d pos_k %d\n", pos_n, pos_k);
    if(pos_n==n+1 && pos_k == k+1) return 0;
    if(pos_k == k+1) return 1e9;

    int &ret = dp[pos_n] [pos_k];

    if(ret != -1) return ret;
    ret = INT_MAX;
    for(int i=pos_n; i<=n-(k-pos_k); i++) {
        ret = min(ret, rec(i+1, pos_k+1)+ calc_unhappiness(pos_n, i));
    }

    return ret;
}

void pre_calc() {
    one[0] = zero[0]=0;

    for(int i=1; i<=n; i++) {
        one[i] = one[i-1] + (ara[i]==1);
        zero[i] = zero[i-1] + (ara[i]==0);
    }
}


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    cin>>n>>k;
    memset(dp, -1, sizeof dp);

    for(int i=1; i<=n; i++) {
        scanf("%d", &ara[i]);
    }
    pre_calc();
    cout<<rec(1, 1);


    return 0;
}





