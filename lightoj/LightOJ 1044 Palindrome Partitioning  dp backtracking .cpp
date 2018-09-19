#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 1010

int dp[MX];
int palin[MX][MX];
int tc, vis[MX][MX];
char str[1010];
//int ara[105];
int n, len;

#define mod 10056

int rec(int pos)
{
//    printf("pos %d val %d\n", pos, val);
    if(pos>len) return 0;

//    if(pos>n  || ara[pos]>val)
//        return -1e9;

    int &ret = dp[pos];
//    int  &v = vis[pos][val];
    if(~ret) return ret;
    ret=1e9;
//    ret=0;
//    v= tc;

    for(int i=len; i>=pos; i--)
    {
        if(palin[pos] [i])
            ret= min(ret, rec(i+1) +1);
    }
//    if(ret>=mod)
//        ret%=mod;

//        printf("s %d f %d turn %d ret %d\n", s, f,turn,  ret);
    return ret;


}


void palin_rec(int i, int j)
{


    if(i==j)
    {
        palin[i][j]=1;
        return;
    }

    if(palin[i+1][j]== -1)
        palin_rec(i+1, j);
    if(palin[i][j-1]== -1)
        palin_rec(i, j-1);

    if(str[i]==str[j])
    {
        if(j-i==1 || palin[i+1][j-1]==1)
        {
//            printf("i %d j %d\n", i, j);
            palin[i][j]=1;
            return;

        }
//        else
//            palin[i][j]=0;
    }
//    else
        palin[i][j]=0;


}


int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    rec(1,1);
    memset(dp, -1, sizeof dp);
    int t, k;
    scanf("%d", &t);

    for(tc=1; tc<=t; tc++)
    {
        scanf("\n%s", str+1);
        str[0] = 1;
        len = strlen(str)-1;
//        cout<<len<<endl;
        memset(palin, -1, sizeof palin);
        memset(dp, -1, sizeof dp);
        palin_rec(1, len);
//        int a,b;
//        while(cin>>a>>b)
//            cout<<palin[a][b]<<endl;

        printf("Case %d: %d\n",tc, rec(1));

    }



    return 0;

}
