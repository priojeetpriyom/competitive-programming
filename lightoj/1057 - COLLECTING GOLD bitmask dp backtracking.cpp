#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 20
//#define max(a,b) {(a>b)? a:b}
//#define min(a,b) {(a<b)? a:b}

struct node{
    int x,y;

} ara[16];

char str[MX];
int lenAra, lim;
int dp[1<<15] [15];
int vis[1<<15] [15];
int tc;
node s;
int n,m;
int dist[16][16];

int CHECK(int mask, int pos) {

    return mask & (1<<pos);

}

int SET(int mask, int pos) {
    return mask | (1<<pos);
}


void pre() {

    for(int i=0; i<lenAra; i++) {
        for(int j=0; j<lenAra; j++) {
            dist[i][j] = max(abs(ara[i].x-ara[j].x), abs(ara[i].y - ara[j].y));
        }
        dist[lenAra] [i] = dist[i][lenAra] =  max(abs(ara[i].x-s.x), abs(ara[i].y - s.y));
    }
//    for(int i=0; i<lenAra; i++)
//        dist[lenAra] [i] = max(abs(ara.x-s.x), abs(ara.y - s.y));


//    printf("a.x %d b.x %d a.y %d b.y %d dist %d\n", a.x, b.x, a.y, b.y, x);
//    return;
}


int rec(int mask, int last) {
//    printf("mask %d last %d\n", mask, last);
    if(mask == lim)
        return dist[last] [lenAra];
    int &ret = dp[mask] [last];
    int &v = vis[mask] [last];
    if(v == tc)
        return ret;
    v =  tc;
    ret = 1<<9;

    for(int i=0; i<lenAra; i++) {
        if(!CHECK(mask, i)) {
            ret = min(ret , rec(SET(mask, i), i) + ((mask==0)? dist[lenAra] [i] : dist[i] [last] ) );
        }
    }
//    printf("mask %d last %d ret %d\n", mask, last, ret);

    return ret;

}



int main()
{

    int t,i;
    scanf("%d", &t);
    for( tc=1; tc<=t; tc++)
    {
//        memset(dp, -1, sizeof dp);
        lenAra=0;
        scanf("%d %d", &n, &m);

        for(int i=0; i<n; i++) {
            scanf("\n%s", str);
            for(int j=0; j<m; j++) {
                if(str[j] =='g') {
                    ara[lenAra++] = {j+1, i+1};
                } else if(str[j]=='x')
                    s.x=j+1, s.y=i+1;
            }
        }

//        for(int i=0; i<lenAra; i++)
//            printf("%d,%d; ", ara[i].x, ara[i].y);
//        printf("\n");


        lim = (1<<lenAra)-1;
        pre();
        printf("Case %d: %d\n",tc, !lim ? 0 :rec(0,0));



    }



    return 0;
}
