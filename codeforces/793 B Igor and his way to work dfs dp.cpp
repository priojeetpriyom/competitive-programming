#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

char grid[1010] [1010];
int dp[1010] [1010] [6] [4], vis[1010] [1010] ;
int n,m;

int start_r, start_c, end_r, end_c;
int east=0, south=1, west=2, north=3;
int rec(int r, int c, int dir, int cnt)
{
//    printf("r %d c %d cnt %d\n", r, c, cnt);
    if(r == n || c == m || r<0 || c<0 || cnt>2 || grid[r][c] == '*')
    {
        return 0;
    }
    if(vis[r] [c])
    {
        return 0;
    }
    if(grid[r][c] == 'T')
    {

//        printf("cnt %d\n", cnt);
        return 1;
    }


    int &ret = dp[r] [c] [dir] [max(cnt,0)];
    if(ret != -1) {
//        printf("Returned\n");
        return ret;
    }
    vis[r][c]=1;



    ret = max(ret, rec(r, c+1, east, cnt+ (dir != east)));
    ret = max(ret, rec(r+1, c, south, cnt+ (dir != south)));
    ret = max(ret, rec(r, c-1, west, cnt+ (dir != west)));
    ret = max(ret, rec(r-1, c, north, cnt+ (dir != north)));
    vis[r][c]=0;
    return ret;
}




int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    memset(dp, -1, sizeof dp);
    cin>>n>>m;

    for(int i=0; i<n; i++)
    {
        scanf("\n%s", grid[i]);
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(grid[i][j] == 'S')
            {
                start_r = i;
                start_c = j;
            }
            if(grid[i][j] == 'T')
            {
                end_r = i;
                end_c = j;

            }
        }
    }
    if(rec(start_r, start_c, 4,-1))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}


