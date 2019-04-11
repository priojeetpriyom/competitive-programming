#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n,m;
int ara [3][1111];
ll dp[1111] [1111], vis[1111];
int tc;
int col[3] [1111];
int row[3][1111];
bool valid(int r, int c, int val)
{




    return (!col[r] [val] && row[ (r&1)+1] [c]!= val);

}

ll rec(int pos, int xx)
{
//    printf("pos %d xx %d\n", pos, xx);
    if(pos <0) return 1;


    ll &ret = dp[pos] [xx];

    if(ret != -1) return ret;
    vis[pos] = tc;
    ret=0;
    for(int i=1; i<=m; i++)
    {
        if(valid(0, pos, i))
        {
            col[0][i] =1;
            row[0][pos] =i;
            for(int j=1; j<=m; j++)
            {
                if(valid(1, pos, j))
                {

                    col[1][j] = 1;
                    row[1] [pos ] =j;
                    ret+= rec(pos-1,xx);
                    ara[1][j]=0;
                    row[1] [pos] =0;
                }
            }
            col[0][i] =0;
            row[0] [pos] =0;
        }
    }
    if(ret>= 1000000007)
    {
        ret%= 1000000007;
    }

    return ret;
}




int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);
    int t;
//    cin>>t;
    scanf("%d", &t);
    memset(dp, -1, sizeof dp);
    for( tc=1; tc<=t; tc++)
    {
        scanf("%d %d", &n, &m);
        printf("%lld\n", rec(n-1, m)/2);
//        cout<<rec(0)<<endl;
    }




    return 0;
}


