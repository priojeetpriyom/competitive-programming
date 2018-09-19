#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 33

int dp[MX][MX], path[MX][MX];

int n;
char str1[MX], str2[MX];
int len1, len2;
int rec(int i, int j)
{

    if(i == len1 || j==len2)
        return dp[i][j]=max(len1 - i, len2-j);

    int &ret = dp[i][j];

    if(~ret) return ret;
    ret=1e9;

    if(str1[i] == str2[j])
    {
        ret = min(ret, rec(i+1, j+1)+1);
    }
    else
    {
        ret = min(rec(i+1, j), rec(i, j+1))+1;
    }
//    printf("i %d j %d ret %d dp[i][j] %d\n", i, j, ret, dp[i][j]);
    return ret;


}
ll dp2[MX][MX];
ll gen(int len, int i, int j)
{

//    printf("i %d j %d len %d\n", i, j , len);
    if(i==len1 || j== len2) return 1;
    if(!len) return 1;

    ll &ret = dp2[i][j];
//    printf("1i %d j %d len %d ret %d dp[i+1][j] %d dp[i][j+1] %d\n", i, j, len, ret, dp[i+1][j], dp[i][j+1]);

    if(~ret) return ret;
    ret=0;
    if(str1[i] == str2[j])
    {
        ret= gen(len-1, i+1, j+1);
    }
    else
    {
        if(dp[i+1][j] == len-1)
        {
            ret += gen(len-1, i+1, j);
        }
        if(dp[i][j+1]== len-1)
        {
            ret += gen(len-1, i, j+1);
        }

    }
//    printf("2i %d j %d len %d ret %d dp[i+1][j] %d dp[i][j+1] %d\n", i, j, len, ret, dp[i+1][j], dp[i][j+1]);
    return ret;
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t;
    scanf("%d", &t);

    for(int tc=1; tc<=t; tc++)
    {
        memset(dp, -1, sizeof dp);
        memset(dp2, -1, sizeof dp2);
        scanf("\n%s \n%s", str1, str2);
        len1 = strlen(str1), len2 = strlen(str2);
        int len = rec(0, 0);
//        printf("GEN CALLED\n");
//        printf("gen %d\n", gen(len, 0, 0));
        printf("Case %d: %d %lld\n",tc, len, gen(len, 0, 0));

    }



    return 0;
}
