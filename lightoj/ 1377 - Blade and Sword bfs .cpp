#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 205
//#define mod 1000000007

int dist[MX][MX];
//int vis[MX];
int t, tc;
vector<pair<int,int> > wildcard;
//int path[MX], len;
//int f;
char grid[MX][MX];
int n, m;
pair<int, int> start, finish;
int dr[] = {1,-1,0,0};
int dc[] = {0,0, 1, -1};
bool firstWildCard;
int bfs()
{
    queue<pair<int, int> > Q;
    Q.push(finish);
    dist[finish.first][finish.second]=0;
    while(!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        int r = cur.first;
        int c = cur.second;
        int distOffset=0;
        if(grid[r][c]=='*')
        {
//        printf("wild_size %d r %d c %d\n",wildcard.size(), r, c);
        int len = Q.size();
           for(int i=0; i<len; i++) {
                int rr = Q.front().first;
                int cc = Q.front().second;
                if(grid[rr][cc]!='*')
                    Q.push(Q.front());
                else
                    {
                        dist[rr][cc]= 1<<30;
                    }
                Q.pop();
           }
            if(wildcard.size()==1)
                {
                    dist[r][c] = 1<<30;
                    continue;
                }
//            if(firstWildCard) {
                distOffset=2;
//            }
            int d = dist[r][c]+1;
            for(int i=0; i< wildcard.size(); i++)
            {
                int rr = wildcard[i].first;
                int cc =wildcard[i].second;
                if(rr!=r || cc!=c)
                {
                    if(d < dist[rr][cc]) {
                        dist[rr] [cc] = d;
                        grid[rr][cc] = '.';
                        Q.push(make_pair(rr, cc));
//                        printf("setting wild r %d c %d dist %d\n",rr,cc,dist[rr][cc]);
                    }
//                    else
//                        printf("not 1setting wild r %d c %d dist %d\n",rr,cc,dist[rr][cc]);
                }
            }
//            continue;
//                dist[r][c] = d;
        }
//        printf("r %d c %d dist %d\n",r, c, dist[r][c]);

        for(int i=0; i<4; i++)
        {
            int rr = r+ dr[i];
            int cc = c+ dc[i];
            if(rr==n+1 || rr==0 || cc==m+1 || cc==0 || dist[rr][cc]<= dist[r][c]+1 || grid[rr][cc]=='#')
                continue;
            else
            {
                dist[rr][cc] = dist[r][c]+1 + distOffset;
                Q.push(make_pair(rr, cc));
            }

        }
    }
}


int main()
{
//freopen("output.txt", "w", stdout);

//    process[0]= {1,2,3};

//    cout<<process[0].id<<" "<<process[0].at<<" "<<process[0].bt<<endl;

    scanf("%d", &t);
//    memset(ncr, -1, sizeof ncr);
//    memset(dp, -1, sizeof dp);
    int x, y;
//        for(int i=1; i<MX; i++)
//        {
//            dist[i] = 1<<30;
//        }
    for( tc=1; tc<=t; tc++)
    {
//    len=0;
//        memset(dist, -1, sizeof dist);
//        memset(vis, 0, sizeof vis);
//        int n;
//        int start;
        scanf("%d %d", &n, &m);

//        ans.clear();
//        path.clear();
        for(int i=1; i<=n; i++)
        {
//            conn[i].clear();
            for(int j=1; j<=m; j++)
                dist[i][j] = 1<<30;
        }
//        len=0;
//        x = start;
//        mx= x;
//        n--;
        wildcard.clear();
        for(int i=1; i<=n; i++)
        {
            scanf("\n%s", grid[i]+1);
            for(int j=1; j<=m; j++)
            {
                if(grid[i][j]=='P')
                {
                    start = make_pair(i,j);
                }
                else if(grid[i][j]=='D')
                {
                    finish = make_pair(i,j);
                }
                else if(grid[i][j]=='*')
                {
                    wildcard.push_back(make_pair(i, j));
                }
            }
//            printf("%s\n", grid[i]+1);
        }
        firstWildCard=true;
        bfs();
//
//        for(int i=1; i<=n; i++)
//        {
////            scanf("\n%s", grid[i]+1);
//            for(int j=1; j<=m; j++)
//            {
//                printf("%3d ", (dist[i][j]==1<<30? -1: dist[i][j] ));
////            printf("%s\n", grid[i]+1);
//            } printf("\n");
//        }


        printf("Case %d: ", tc);

        if(dist[start.first] [start.second] == 1<<30)
            printf("impossible\n");
        else
            printf("%d\n", dist[start.first] [start.second]);
//        dfs(y, 0);
//        for(int i=1; i<=n; i++)
//            printf("%d ", dist[i]);
//            printf("\n");
//        printf("bfs oka\n");
//        f=y;
//        find_path(start);
//        for(int i=0; i<len-1; i++)
//            printf("%d ", path[i]);
//        printf("%d\n", path[len-1]);
    }
//    printf("\n");


    return 0;
}
