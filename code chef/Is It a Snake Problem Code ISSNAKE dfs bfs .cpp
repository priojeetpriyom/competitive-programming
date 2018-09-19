#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int vis[505] [505];
int n;
char grid[3] [505];
int y[] = {1,-1,0,0};
int x[] = {0,0,1,-1};
bool ans;
int snake_cnt=0, cnt;
int tc;

bool val_pos(int r, int c)
{
    return !(r==2 || c==n || r<0 || c<0);
}

void dfs(int r,int c, int cnt)
{
//    printf("r %d c %d cnt %d\n", r, c, cnt);
    if(cnt == snake_cnt)
    {
        ans = true;

        return;
    }
//    if( || grid[r][c]!= '#') return;
    vis[r][c] = tc;
//    printf("row %d col %d vis %d\n", r, c, vis);

    for(int i=0; i<4; i++)
    {
        int rr=r + y[i];
        int cc = c+ x[i];
        if(val_pos(rr,cc) && grid[rr][cc]=='#' && vis[rr][cc]!= tc)
        {
//            if(!ans)
            dfs(rr, cc, cnt+1);
        }
    }
//    vis[r][c]=0;
}



int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    int t;
    scanf("%d", &t);

    for( tc=1; tc<=t; tc++)
    {
        scanf("%d", &n);
//        cincin.ignore();
        scanf("\n%s \n%s", grid[0], grid[1]);
//        printf("aise\n");
//        cout<<grid[0]<<endl<<grid[1]<<endl;
        ans=false;
        snake_cnt=0;
        for(int i=0; i<2; i++)
        {
            for(int j=0; j<n; j++)
            {
                snake_cnt += (grid[i][j]=='#');
            }
        }
//        printf("snake_cnt %d\n", snake_cnt);

        cnt=0;
        for(int j=0; j<n; j++)
        {

            if(grid[0][j] == '#' && grid[1][j]=='#')
            {
                vis[0] [j] = vis[1][j] = tc;
                cnt=2;
                while( grid[0][j+1] == '#' && grid[1][j+1]=='#' && j<n-1) {
                    j++;
                    vis[0] [j] = vis[1][j] = tc;
                    cnt+=2;
                }

                if(j==n-1)
                {
                    ans = true;
                    break;
                }
                else
                {
                    if(grid[0][j+1]=='#')
                    {
                        dfs(0, j+1, cnt+1);
                    }
                    else if(grid[1] [j+1] == '#')
                    {
//                        printf("j %d cnt %d\n", j+1, cnt+1);
                        dfs(1, j+1, cnt+1);
                    }
                    else
                    {
                        if(cnt == snake_cnt)
                            ans = true;
                        else
                            ans = false;
//                        for(j = j+1; j<n; j++) {
//                            if(grid[0][j]== '#' || grid[1][j] =='#') {
//                                ans = false;
//                                break;
//                            }
//                        }
                        break;
                    }

                }


//                }

                break;
            }

            else if(grid[0][j] == '#')
            {
                dfs(0,j, cnt+1);

                break;
            }
            else if(grid[1][j] == '#')
            {
                dfs(1,j, cnt+1);

                break;

            }
        }

        if(ans) printf("yes\n");
        else printf("no\n");


    }


    return 0;

}
