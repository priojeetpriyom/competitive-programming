#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 1010

int dp[MX], vis[MX];
int tc; //, vis[MX][MX] [MX];
int len;
//ll run=1;
char str[1010];
bool palin[1010] [1010];

bool is_pal(int s, int f)
{
//    printf("s %d f %d pal %d\n", s,f, palin[s][f]);

    return palin[s][f];
//    int lim = (f-s+1)/2 +s;
//
//    for(int i = s; i<lim; i++ ) {
//        if(str[i] != str[f- (i-s)])
//            return false;
//    }

//    return true;


}

int rec(int pos)
{
//        printf("pos %d\n", pos);
    if(pos == len)return 0;
    int &ret = dp[pos];
    if(vis[pos] == tc) return ret;
    vis[pos] = tc;
    ret = 1e9;
    for(int i=pos; i<len; i++)
    {
        if(is_pal(pos, i))
        {
//            printf("from %d calling for %d ret %d\n",pos,  i, rec(i+1)+1);
            ret = min(ret, rec(i+1)+1);

        }
    }

//        printf("s %d f %d turn %d ret %d\n", s, f,turn,  ret);
    return ret;


}

void pre()
{
    ///pre calculating all palindroms
    for(int i=0; i<len; i++)
        palin[i] [i]=1;

    for(int i=2; i<=len; i++)
    {
        for(int j=0; j<= len-i; j++)
        {
            if(i==2) palin[j][i+j-1] = (str[j] == str[i+j-1]);
            else palin[j][(i-1)+j] = (str[j]==str[(i-1)+j]) & palin[j+1] [(i-1)+j-1];
        }
    }


}


int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t;
    scanf("%d", &t);
    memset(dp, -1, sizeof dp);
    for(tc=1; tc<=t; tc++)
    {
        scanf("\n%s", str);
        len = strlen(str);

        pre();
//        printf("len %d\n", len);
        printf("Case %d: %d\n",tc, rec(0));

    }



    return 0;
}
