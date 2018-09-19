#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t,w,n,dp[33] [1010], val[33] , dist[33], mx, dir[33] [1010];
vector<int> path, ans;

int calc_time(int d) {
    return 3*w*d;
}

int rec(int pos, int time) {
    if(time<0)
        return -val[pos-1];
    if(pos==n) {
        return 0;
    }
    if(dp[pos][time] != -1) return dp[pos] [time];

    int x=0, y=0;
    x = rec(pos+1, time- calc_time(dist[pos]))+val[pos];
    y = rec(pos+1, time);

    if(x>y) {
//        printf("pos %d niye %d na_niye %d\n", pos, x, y);
        dir[pos][time] = 1;
        dp[pos] [time] = x;
    } else {
        dir[pos][time] =0;
        dp[pos] [time] = y;
    }
    return dp[pos] [time];


}

int count_val(int ans) {
    int i=0;
    int time = t, cnt=0;
    while(ans>0) {
//        printf("ans %d\n", ans);
        if(dir[i] [time]) {
            time-= calc_time(dist[i]);
            ans-= val[i];
            cnt++;
        }
        i++;
    }
    return cnt;
}
void print_sol(int ans) {
    int i=0;
    int time = t, cnt=0;
    while(ans>0) {
//        printf("ans %d\n", ans);
        if(dir[i] [time]) {
            time-= calc_time(dist[i]);
            ans-= val[i];
            printf("%d %d\n", dist[i], val[i]);
        }
        i++;
    }
//    return cnt;
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int tt=0;
    while(scanf("%d %d", &t, &w)==2) {
        mx = INT_MIN;
        memset(dir, 0, sizeof dir);
        memset(dp, -1, sizeof dp);
        if(tt)
            printf("\n");
        else tt++;

        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d %d", &dist[i], &val[i]);
        }
        int ans = rec(0, t);
        printf("%d\n", ans);
//        int cnt=0;
//        for(int i=0; i<n; i++) {
//            if(dir[i]) {
//                cnt++;
//            }
//        }
        printf("%d\n", count_val(ans));
        print_sol(ans);
//        for(int i=0; i<n; i++) {
//            if(dir[i]) {
//                printf("%d %d\n", dist[i], val[i]);
//            }
//        }
    }



    return 0;
}




