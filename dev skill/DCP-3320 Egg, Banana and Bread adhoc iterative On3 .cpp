#include<bits/stdc++.h>

using namespace std;

typedef long long ll;




int main()
{


//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int t;
//    cout<<10-3-1;

    cin>>t;
    int x,y,z,money;
    for(int tc=1; tc<=t; tc++) {
//        memset(dp, -1, sizeof dp);
        scanf("%d %d %d %d", &x, &y, &z, &money);
        int cost=0;
        int ans = 1e9;
        for(int i=1; (i*x)<= money; i++) {
            for(int j = i+1; (i*x)+(j*y)<= money; j++) {
                for(int k = j+1; (i*x) + (j*y) + (k*z)<=money; k++) {
                    cost = (i*x) + (j*y) + (k*z);
                    ans = min(ans, money-cost);
                }
            }
        }

        printf("%d\n", (ans==1e9)? -1: ans);

    }

    return 0;

}

