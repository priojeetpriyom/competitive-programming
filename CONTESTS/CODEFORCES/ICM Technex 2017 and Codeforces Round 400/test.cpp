#include <bits/stdc++.h>

using namespace std;
int n, hit[20] [20], life[20], dp[1<<15+5] [20];
char str[20];
int lim;
int divide(int a, int b) {
    a+=b;
    return (a-1)/b;
}

int SET(int n, int pos) {
    n = (n | (1<<pos));
    return n;
}

int CHECK(int n, int pos) {
    return (n & (1<<pos));
}
vector<int> path;
int rec(int mask, int prev, int cost) {
//    printf("mask %d\n", mask);
    if(mask == lim)
    {
        for(int i=0; i<path.size(); i++) {
            printf("%d ",path [i]);
        }
        printf("cost %d\n", cost);
        return 0;
    }

    int &ret = dp[mask] [prev] ;
    if(ret!= -1)
    {
        for(int i=0; i<path.size(); i++) {
            printf("%d ",path [i]);
        }
        printf("returned dp %d; cost %d\n", ret, cost);

        return ret;
    }

    int x = 1e9;
//    if(!mask) {
//        for(int i=0; i<n; i++) {
//            x = min(x, rec(SET(mask, i), i) + life[i] );
//        }
//    } else {
//    bool stopped = true;

        for(int i=1; i<=n; i++ ) {
            if(!CHECK(mask, i)) {
//                stopped = false;
                if(hit[prev] [i]) {
                    path.push_back(i+1);
                    x = min(x, rec(SET(mask, i), i, cost+ divide(life[i] , hit[prev] [i])) + divide(life[i] , hit[prev] [i]));
                    path.pop_back();
                } else {
                    path.push_back(i+1);
                    x = min(x, rec(SET(mask, i), i, cost+life[i]) + life[i] );
                    path.pop_back();
                }

            }
        }
//        if(stopped) {
//            for(int i=0; i<n; i++) {
//                if(!CHECK(mask, i))
//                    x = min(x, rec(SET(mask, i), i) + life[i] );
//        }
//        }

//    }
    return ret = x;
}

int main() {
    int t;
    cin>>t;

    for(int tc=1; tc<=t; tc++) {
        memset(dp, -1, sizeof dp);
        scanf("%d", &n);

        for(int i=1; i<=n; i++) {
            scanf("%d", &life[i]);
        }
        for(int i=1; i<=n; i++) {
            scanf("\n%s", str);

//        printf("%s\n", str);
            for(int j=0; j<n; j++)
            {
                hit[i][j+1] = str[j] - '0';
                if(i==j+1)
                    hit[i][j+1]=0;
            }
        }
        lim = (1<<(n+1))-2;
        printf("Case %d: %d\n",tc, rec(0, -1, 0));
    }

    return 0;
}
