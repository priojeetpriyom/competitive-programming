#include <bits/stdc++.h>
using namespace std;

int dp[32777], len;
int sqrs[102];
//int mn;
int rec(int n,int pos, int cnt) {
//    cout<<pos<<endl;

    if(n==0)
    {
//        printf("cnt %d\n", cnt);
//        mn = min(mn, cnt);
        return 0;
    }
    if(n<0 || pos==101)
        return 100000;

//    for(int i=0; i<100; i++)
//            printf("%d ",dp[i]);
//        printf("\n");
//        if(cnt == 0)
//            height = ara[pos];
    int &ret = dp [n];
//    printf("height %d cnt %d ret %d\n", height, cnt, ret);

    if(ret != 100000) {
//        mn = min(mn, ret+cnt);
        return ret;
    }
    int ans = 100000;
//    if(n >= sqrs[pos])
        ans = min(ans, rec(n-sqrs[pos], pos, cnt+1)+1);

        ans = min(ans, rec(n, pos+1, cnt));

    return ret = min(ret,ans);
//    return ret;
}


int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);
    for(int i=0; i<10001; i++)
        dp[i] = 100000;

    for(int i=1; i<101; i++)
        sqrs[i] = i*i;
    int n,t=0;
    scanf("%d", &t);
//    while(1) {
//        mem();
//        memset(dp, -1, sizeof(dp));
//        for(int i=0; i<100; i++)
//            printf("%d ",dp[i]);
//        printf("\n");
//        len=0;

//        t++;
        for(int i=1; i<10001; i++)
        {
//            mn= INT_MAX;
            rec(i, 1, 0);
//            dp[i] = mn;
        }

        while(t--) {
            scanf("%d", &n);
//             mn= INT_MAX;
//            rec(n, 1, 0);
//            dp[n] = mn;
            printf("%d\n", dp[n]);
        }
//        if(len==0)
//            break;
//        if(t>1)
//            printf("\n");
//        printf("Test #%d:\n  maximum possible interceptions: %d\n",t, rec(0,0,32776));
//        cout<<<<endl;

//    }


    return 0;
}
