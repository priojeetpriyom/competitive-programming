#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 105

int dp[MX][MX];

int n;
char str[MX];

int rec(int i, int j)
{
//    printf("i %d j %d\n", i, j);
    if(i>j)
        return 0;

    int &ret = dp[i][j];

    if(~ret) return ret;
    ret=1e9;

    if(str[i] == str[j])
    {
        ret = min(ret, rec(i+1, j-1));
    }
    else
    {
        ret = min(rec(i+1, j), rec(i, j-1))+1;
    }
//    printf("i %d j %d ret %d\n", i, j, ret);
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
//        memset(dp2, -1, sizeof dp2);
        scanf("\n%s", str);
//        len1 = strlen(str1), len2 = strlen(str2);
//        int len = rec(0, 0);
//        printf("GEN CALLED\n");
//        printf("gen %d\n", gen(len, 0, 0));
        printf("Case %d: %d\n",tc, rec(0, strlen(str)-1));

    }



    return 0;
}
