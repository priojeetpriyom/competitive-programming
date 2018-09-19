#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

string grid[21];
int dist[21][21];
vector <pair<int, int> > dir;
int n,m;
void bfs(int r,int c) {

    queue<pair<int, int> > Q;
    Q.push(make_pair(r,c) );
        dist[r][c]=0;

    while(!Q.empty()) {

        r= Q.front().first;
        c = Q.front().second;

//        printf("r %d c %d dist %d\n",r,c, dist[r][c]);
        Q.pop();
        for(int i=0; i<4; i++) {
                char charr = grid[r+dir[i].first  ] [ c+dir[i].second ];
            int rr = r+dir[i].first, cc= c+dir[i].second;
            if(rr>=0 && rr<n && cc>=0 && cc<m &&  charr!='#' && charr!= 'm' && (dist[r][c]+1 < dist[rr][cc]) ) {
                dist[rr][cc] = dist[r][c]+1;
                Q.push(make_pair(rr,cc));
            }

        }




    }

}


int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    for(int tc=1; tc<=t; tc++) {
//        memset(vis, 0, sizeof vis);
        for(int i=0; i<21; i++)
            for(int j=0; j<21; j++)
                dist[i][j] = 100000;

        dir.push_back(make_pair(1,0));
        dir.push_back(make_pair(-1,0));
        dir.push_back(make_pair(0,1));
        dir.push_back(make_pair(0,-1));

        cin>>n>>m;

        for(int i=0; i<n; i++)
            cin>>grid[i];

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]=='h') {
                    bfs(i, j);
                    break;
                }
            }
        }
//        for(int i=0; i<n; i++) {
//            for(int j=0; j<m; j++) {
//                printf("%6d ", dist[i][j]);
//            }
//            printf("\n");
//        }






//        printf("aise\n");
        int ans  = -1e5;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]>='a' && grid[i][j]<='c') {

                    ans = max(ans, dist[i][j]);
                }
            }
        }
        printf("Case %d: %d\n",tc, ans);
    }

    return 0;

}

