#include <bits/stdc++.h>

using namespace std;
int n, hit[20] [20], life[20], dp[1<<15+5];
char str[20];
int lim;
int divide(int a, int b) {
    a+=b;
    return (a-1)/b;
}

int SET(int nn, int pos) {
    nn = (nn | (1<<pos));
    return nn;
}

int CHECK(int nn, int pos) {
    return (nn & (1<<pos));
}
int cnt=0;
int rec(int mask) {
    if(mask == lim) return 0;

    int &ret = dp[mask];

    if(ret!= -1) return ret;
    ret = 1e9;
//    if(!mask) {
//        for(int i=0; i<n; i++) {
//            ret = min(ret, rec(SET(mask, i)) + life[i] );
////            printf("mask %d ret %d\n", mask, ret);
//        }
//    } else
    {
        for(int i=0; i<n; i++) {
            if(!CHECK(mask, i)) {
                    int mx=1;
//                    int flag=1;
                for(int j=0; j<n; j++) {
                    if(CHECK(mask, j) && hit[j][i]) {
                            mx = max(mx, hit[j][i]);
//                        flag=0;
//                        ret= min(ret, rec(SET(mask, i)) + divide(life[i], hit[j][i])) ;
                    }

                }
//                if(flag)
                        ret= min(ret, rec(SET(mask, i)) + divide(life[i], mx)) ;

            }

        }

    }

    return ret;



}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);


    int t;
    cin>>t;

    for(int tc=1; tc<=t; tc++) {
        memset(dp, -1, sizeof dp);
        scanf("%d", &n);

        for(int i=0; i<n; i++) {
            scanf("%d", &life[i]);
        }
        for(int i=0; i<n; i++) {
            scanf("\n%s", str);

//        printf("%s\n", str);
            for(int j=0; j<n; j++)
            {
                hit[i][j] = str[j] - '0';
                if(i==j)
                    hit[i][j]=0;
            }
        }
        lim = (1<<n)-1;
        printf("Case %d: %d\n",tc, rec(0));
    }

    return 0;
}
