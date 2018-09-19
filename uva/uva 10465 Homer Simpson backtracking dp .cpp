#include <bits/stdc++.h>
using namespace std;
int m,n, mx, mn_time, dp[10010] ;
bool withoutBeer;

void rec(int time, int cnt) {
    if(time <0)
        return;
//    if(time==0) {
//        if(withoutBeer)
//            mx = max(mx, cnt);
//        else {
//            mx = cnt;
//            withoutBeer = true;
//        }
//        mn_time = time;
//    }

    if(time <m && time <n) {
        if(time < mn_time) {

            mx = cnt;
            mn_time = time;
        }
        else if(time == mn_time) {
            mx = max(mx, cnt);
        }
        return;
    }

    int &ret = dp[time] ;
    if(ret!= 0)
        return;

    rec(time-m, cnt+1);
    rec(time-n, cnt+1);
    ret = 1;
}

int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);
    int t=1;
    while(scanf("%d %d %d", &m, &n, &t)==3) {
        if(m>n)
            swap(m,n);
        memset(dp, 0, sizeof(dp));
        withoutBeer =false;
        mx = INT_MIN;
        mn_time = INT_MAX;
        rec(t, 0);
        printf("%d", mx);
        if(mn_time!=0)
            printf(" %d", mn_time);
        printf("\n");
    }

    return 0;
}
