#include<bits/stdc++.h>

using namespace std;

typedef long long ll;



    int cum_r[505] [505], cum_c[505] [505];

int main()
{


//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n, m;
    cin>>n>>m;
    char c;
    memset(cum_c, -1, sizeof cum_c);
    memset(cum_r, -1, sizeof cum_r);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            scanf("\n%c", &c);
            if(c!= 'x') {
                cum_r[i][j] = cum_r[i-1][j]+1;
                cum_c[i][j] = cum_c[i][j-1]+1;
            }
        }
    }
//
//    printf("cum_row\n");
//    for(int i=1; i<=n; i++) {
//        for(int j=1; j<=m; j++) {
//            printf("%d ",cum_r[i][j] );
//        }
//        printf("\n");
//    }
//    printf("cum_col\n");
//    for(int i=1; i<=n; i++) {
//        for(int j=1; j<=m; j++) {
//            printf("%d ", cum_c[i][j]);
//        }
//        printf("\n");
//    }





    int ans=0;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {

            for(int k = i; k<=n && cum_r[k][j]>=0; k++) {
                if(cum_c[k] [j]>0 && cum_r[k][j]>0) {
                   int mn_c = min(cum_c[i][j], cum_c[k][j]);
//                   if(mn_c==5) {
//                    printf("i %d j %d k %d mn_c %d\n",i,j,k, mn_c);
//                   }
                   if(cum_r[k][j-mn_c] == cum_r[k][j]) {
                        mn_c = ( (cum_r[k][j])<<1 ) + ( (mn_c )<<1 );
                        if( mn_c>ans) ans= mn_c;
                   }
                }
            }

        }
    }
    if(ans<=0) printf("impossible\n");
    else
        printf("%d\n", ans);



    return 0;

}

