/// Jane can only pass a point if she reaches that point before the fire does. we can easily compare it by throwing dfs from every fire and then from janes position.

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 202


struct node
{
    int r, c, cost=0;
    node()
    {
    }
    node(int rr, int cc, int cost)
    {
        r = rr;
        c = cc;
        this->cost = cost;
    }
};
char grid [MX] [MX];
//const int reached = 15;
int n, tc, m;
//struct node


int vis[MX][MX];
int dist[MX] [MX];
int xx=0;

int dirr[] = {-1, 0, 1, 0}, dirc[] = {0, 1, 0, -1};
//int mn;
int x=0;

int bfs(node start, int saveDist=0)
{
    x++;

//    xx++; ///used to avoid memset of vis
//    memset(vis, 0, sizeof vis);
    queue<struct node > Q;
    Q.push(start);
//
    while(!Q.empty())
    {
//        printf("q size %d\n", Q.size());
        node cur  = Q.front();
        Q.pop();
        int r, c;
        r = cur.r;
        c = cur.c;

//        printf("r %d c %d\n", r, c);
        if(r<0 || r==n || c<0 || c==m) {
            if(!saveDist)
                return cur.cost;
            else
                continue;
        }
        else if(grid[r][c] =='#')
            continue;
        vis[r][c] = x;
//        if(!saveDist) {
            if(cur.cost>= dist[r][c])
                continue;
//        }
//        printf("passed boundary\n");


//        printf("ok\n");

        if(saveDist) {
            dist[r] [c] =  cur.cost;
        }

        for(int i=0; i<4; i++)
        {
            int rr=r, cc=c;

//            if(grid[arr][acc]!='X') {
            rr = r + dirr[i];
            cc = c + dirc[i];

//            if(arr<0 || arr==n || acc<0 || acc==n || grid[arr][acc]=='#' || brr<0 || brr==n || bcc<0 || bcc==n || grid[brr][bcc]=='#' || crr<0 || crr==n || ccc<0 || ccc==n || grid[crr][ccc]=='#')
//                continue;
//            else if(vis[arr][acc][brr][bcc][crr][ccc]!=tc)
//            {
            if(vis[rr][cc]!=x)
            {
                Q.push(node(rr, cc, cur.cost+1));
                vis[rr][cc]=x;
            }
//                vis[arr][acc][brr][bcc][crr][ccc]=tc;
//            }


        }





    }
    return 1e9;


//    return -1;

}



int main()
{
//    cout<<-13%5;
//    freopen("out.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    ios_base::sync_with_stdio(false);
//    cin.tie(false);

    int t;
    scanf("%d", &t);
    for(tc=1; tc<=t; tc++)
    {
//        memset(grid, 0, sizeof grid);
//        memset(dist1, 0, sizeof dist1);
//        memset(dist2, 0, sizeof dist2);

        scanf("%d %d", &n, &m);
        for(int i=0; i<n; i++)
        {
            scanf("\n%s", grid[i]);
        }
//        for(int i=0; i<n; i++) {
//            printf("%s\n", &grid[i]);
//        }

        node start;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++){
               dist[i][j] = 1e9;
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]=='F')
                {
                    bfs(node(i, j, 0), 1);
                }
                else if(grid[i][j] == 'J') {
                    start = node(i,j,0);
                }
            }
        }
//        for(int i=0; i<n; i++)
//        {
//            for(int j=0; j<m; j++)
//            {
//                printf("%d ", dist[i][j]);
//            }
//            printf("\n");
//        }
//        mn= 1e9;
        int mn = bfs(start);
//
////        for(int i=0; i<n; i++)
////            printf("%d ", dist2[i]);
////        printf("\n");
//
        printf("Case %d: ", tc);

        if(mn==1e9)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", mn);
//        for(int i=0; i<n; i++) {
//            printf("%d\n", max(dist1[i], dist2[i]));
//        }

    }



    return 0;
}
