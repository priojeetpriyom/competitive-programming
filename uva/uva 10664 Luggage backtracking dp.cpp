#include <bits/stdc++.h>
using namespace std;

int dp[4002] [22];
int len, ara[22];

int rec(int sum, int pos) {
//    printf("pos %d sum %d\n", pos, sum);
    if(pos == len)
    {
//        printf("return e aise\n");
        if(sum==0)
            return 1;
        else
            return 0;
    }

    int &ret = dp[abs(sum)] [pos];

    if(ret!= -1){
//        printf("kita oilo sum %d ret %d\n",sum, ret);
        return ret;
    }
    int ans = -1;
    ans = max(ans, rec(sum+ara[pos], pos+1));
    ans = max(ans, rec(sum-ara[pos], pos+1));
    return ret=max(ret, ans);
}


int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);

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
//        for(int i=1; i<10001; i++)
//        {
////            mn= INT_MAX;
//            rec(i, 1, 0);
////            dp[i] = mn;
//        }

//        int n;
    getchar();
    while(t--) {
//        mem();
        memset(dp, -1, sizeof(dp));
//        for(int i=0; i<100; i++)
//            printf("%d ",dp[i]);
//        printf("\n");
        len=0;
        string str;
//        t++;
        getline(cin, str);
        int l = str.length();
//        printf("l %d\n", l);
        for(int i=0;i<l; i++) {

            for(int j = i; j<=l; j++) {
                if(str[j] == ' ' || j==l) {
                    ara[len++] = atoi(str.substr(i, j-i).c_str());
//                    printf("n %d\n",ara[len-1]);
                    i=j;
                    break;
                }
            }
        }



//        while(scanf("%d", &n) ==1 ) {
//            ara[len++] = n;
//        }
//        if(len==0)
//            break;
//    printf("len %d\n", len);
        int x = rec(0, 0);
//        if(x== -1)
//            printf("baal\n");
        if(x==1)
            printf("YES\n");
        else
            printf("NO\n");

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
