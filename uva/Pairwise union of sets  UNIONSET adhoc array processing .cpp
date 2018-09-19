#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int ara[2555] [10100], vis[2555];
int v=1;



int main()
{


//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    int t;

    scanf("%d", &t);
    int n, k, len;
    for(int tc=1; tc<=t; tc++) {
        scanf("%d %d", &n, &k);

        for(int i=1; i<=n; i++) {
            scanf("%d", &len);
            ara[i][0] = len;

            for(int j=1; j<=len; j++) scanf("%d", &ara[i][j]);
        }

        int ans=0;

        for(int i=1; i<=n; i++)  {
            v++;
            int cnt=0;
            len  = ara[i][0];
            for(int j =1; j<=len; j++) {
                if(vis[ara[i][j]] != v) {
                    vis[ara[i][j] ] = v;
                    cnt++;
                }
            }

                int v_temp = v;

            for(int j = i+1; j<=n; j++) {
                v_temp++;
                int cnt2 = cnt;
                len = ara[j][0];
                for(int k=1; k<= len; k++) {
                    if(vis[ara[j][k] ] != v && vis[ ara[j][k] ]!= v_temp) {
                        vis[ ara[j][k] ] = v_temp;
                        cnt2++;
                    }
                }
//                printf("i %d j %d len %d cnt %d cnt2 %d\n", i, j,len, cnt, cnt2);
                if(cnt2==k) ans++;

            }
            v = v_temp;

        }


        printf("%d\n", ans);




    }



    return 0;
}





