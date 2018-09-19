#include <bits/stdc++.h>
using namespace std;

int ara[32777],dp[32777], len;

int rec(int pos, int cnt, int height) {


    if(pos == len)
    {
//        printf("cnt %d\n", cnt);
        return cnt;
    }

//    for(int i=0; i<100; i++)
//            printf("%d ",dp[i]);
//        printf("\n");
        if(cnt == 0)
            height = ara[pos];
    int &ret = dp [cnt];
//    printf("height %d cnt %d ret %d\n", height, cnt, ret);

    if(ret > height)
        return ret;

    if(height >= ara[pos])
        ret = max(ret, rec(pos+1, cnt+1, ara[pos]));

    ret = max(ret, rec(pos+1, cnt, height));

    return ret;

}


int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);
    int n,t=0;
    while(1) {
//        mem();
        memset(dp, -1, sizeof(dp));
//        for(int i=0; i<100; i++)
//            printf("%d ",dp[i]);
//        printf("\n");
        len=0;

        t++;
        while(scanf("%d", &n) ==1 && n!= -1) {
            ara[len++] = n;
        }
        if(len==0)
            break;
        if(t>1)
            printf("\n");
        printf("Test #%d:\n  maximum possible interceptions: %d\n",t, rec(0,0,32776));
//        cout<<<<endl;

    }


    return 0;
}

