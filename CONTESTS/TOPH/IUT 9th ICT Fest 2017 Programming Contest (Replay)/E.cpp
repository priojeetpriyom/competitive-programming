#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 55

int n, m;
//int coins[20];
int dp[2<<15+5] [20];
int vis[2<<15+5] [20];
int tc, lim;
int coins[20], vals[20];

int CHECK(int mask, int pos) {
    return mask & (1<<pos);
}

int SET(int mask, int pos) {
    return mask | (1<<pos);
}

//int CHECK(int mask, int pos) {
//    return mask & (1<<pos);
//}



int rec(int mask, int pos)
{
    if(mask == lim || pos == m)
//    printf("mask %d val[%d]\n", mask, vals[pos]);
    if(pos == m) return 0;
    if(vals[pos]<0 || mask == lim) return 1e9;

    int &ret = dp[mask] [pos];

    if(vis[mask] [pos] == tc)
        return ret;
    vis[mask] [pos] = tc;
    ret = 1e9;


    for(int i=0; i<n; i++) {
        if(!CHECK(mask, i)) {
            vals[pos]-= coins[i];
            ret = min(ret, rec(SET(mask, i), pos + (vals[pos]==0) ) +1);
            vals[pos]+= coins[i];
        }
    }


    return ret;
}


int main()
{

    int t;
    scanf("%d", &t);
//    memset(dp, -1, sizeof dp);

    for(tc=1; tc<=t; tc++)
    {
        scanf("%d", &n);


        for(int i=0; i<n; i++)
        {
            scanf("%d", &coins[i]);
        }
        scanf("%d", &m);

        for(int i=0; i<m; i++)
        {
            scanf("%d", &vals[i]);
        }

        printf("Case %d: ", tc);

        lim = (1<<n)-1;
//        printf("lim %d\n", lim);
        if(rec(0, 0)>= 1e9)
        {
            printf("-1\n");
        }
        else
            printf("%d\n", rec(0,0));



    }



    return 0;
}

