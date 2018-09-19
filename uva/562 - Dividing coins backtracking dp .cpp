#include <bits/stdc++.h>
using namespace std;

int n,t;
int ara[101], dp[50005] [101];

int rec (int dif, int cnt) {

     if(cnt==n){
//        printf("diff %d abs %d\n", dif, abs(dif));
        return abs(dif);
     }

     int &ret = dp[abs(dif)] [cnt];

     if(ret!= -1)
        return ret;
     ret = INT_MAX;

     ret = min(ret, rec(dif+ara[cnt], cnt+1));
//        printf("1 returned %d cnt %d\n", dp[dif] [cnt], cnt);

     ret = min(ret, rec(dif-ara[cnt], cnt+1));
//        printf("2 returned %d cnt %d\n", dp[dif] [cnt], cnt);

     return ret;
}

int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);

    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);

        for(int i=0; i<n; i++)
            scanf("%d", &ara[i]);

        memset(dp, -1, sizeof(dp));

        printf("%d\n", rec(0,0));

    }

    return 0;
}

