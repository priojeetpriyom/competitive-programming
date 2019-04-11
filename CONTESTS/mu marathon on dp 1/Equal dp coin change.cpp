#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

//#include <stdio.h>
//#include <string.h>
//#define ll long long

int dp[1111], ara[11111];

int rec(int n) {

    if(!n) return 0;
    if(n<0) return 11111;

    int &ret = dp[n];
    if(ret!= -1) return ret;
    ret=0;

    return ret = min(rec(n-1), min(rec(n-2), rec(n-5)) ) +1;

}


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    memset(dp, -1, sizeof dp);
    dp[0]=0;
    for(int i=1; i<= 1000; i++) {
        rec(i);

    }

//    for(int i=1; i<=100; i++) printf("i %d dp %d\n", i, dp[i]);

    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;
        int mn = 1e6;

        for(int i=0; i<n; i++) {
            cin>>ara[i];
            mn = min(mn, ara[i]);
        }
//        printf("mn %d\n", mn);
        int ans=1e6;
        for(int i=0; i<5; i++) {

            if(mn-i<0) break;
            else {
                int x=0;
                for(int j=0; j<n; j++) {
                    x+= dp[ ara[j] - (mn-i) ];
//                    printf("i %d j %d ara_j %d mn %d dp %d\n",i,j,ara[j], mn-i, dp[ara[j]-(mn-i)  ]);
                }
//                if(i==1 || i==2) x++;
//                else if(i==3|| i==4) x+=2;
//                printf("i %d x %d\n", i, x);
//                if(x!= -1)
                ans = min(ans, x);
            }
        }
        cout<<ans<<endl;
    }




    return 0;
}

