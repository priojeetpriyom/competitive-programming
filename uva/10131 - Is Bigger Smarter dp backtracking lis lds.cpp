#include<bits/stdc++.h>

using namespace std;

int n=1, dp[1005] , dir[1005] , w[1005], iq[1005], taken[1005];

int rec(int pos) {


    int &ret = dp[pos];
    if(ret != -1) return ret;

    for(int i=1; i<=n; i++) {
        if(!taken[i] && w[i]> w[pos] && iq[i]<iq[pos]) {
            taken[i]=1;
            int x = rec(i)+1;
            taken[i] = 0;
            if(x> ret) {
                ret = x;
                dir[pos] = i;
            }
        }
    }
    return max(ret,0);
}

void print_path(int pos) {
    if(pos == 1e9) return;

//    if(dir[pos] [prev]) {
        if(pos) printf("%d\n", pos);
        print_path(dir[pos]);
//    } else {
//        print_path(pos+1, prev);
//    }
}

int main(){


//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    memset(dp, -1, sizeof dp);
    while(scanf("%d %d", &w[n], &iq[n])==2) {
        dir[n] = 1e9;
        n++;
    }
//    printf("n is %d\n", n);
    w[0] = INT_MIN;
    iq[0] = INT_MAX;
    int ans = rec(0);
    printf("%d\n", ans);
    print_path(0);
    return 0;
}

