#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 15

struct node
{
    int r, c;
    int dist;
    node(int rr=0, int cc=0, int dd = 0)
    {
        r = rr;
        c = cc;
        dist =dd;
    }
//    node(int rr, int cc, int dd) {
//        r = rr;
//        c = cc;
//        dist = dd;
//    }
};

int n, m,q;
string grid[MX];

int cnt[MX] [MX], dist[MX] [MX];
int dirR[] = {2, -2, 1, -1, 2, -2, 1, -1};
int dirC[] = {1, 1, 2, 2, -1, -1, -2, -2};

int process(int val, int div)
{
    return val/div + (val%div!=0);
}
int bfs(node start, int k)
{
    int vis[MX] [MX];
    memset(vis, 0, sizeof vis);
    queue<node> Q;
    Q.push(start);

    while(!Q.empty())
    {
        node cur = Q.front();
        Q.pop();
        int & r = cur.r;
        int & c = cur.c;
        if(vis[r][c] || r<0 || r>=n || c<0 || c>=m)
            continue;
        vis[r][c]=1;
        cnt[r][c]++;
        dist[r][c] += ( process(cur.dist, k));


        for(int i=0; i<8; i++) {
            Q.push(node(r+dirR[i], c+dirC[i], cur.dist+1));
        }

    }


//    return -1;

}



int main()
{
//    cout<<-13%5;
//    freopen("out.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(false);

    ll t, q;
    cin>>t;
    cin.ignore();
    for(int tc=1; tc<=t; tc++)
    {
        memset(cnt, 0, sizeof cnt);
        memset(dist, 0, sizeof dist);
        cin>>n>>m;
        for(ll i=0; i<n; i++)
            cin>>grid[i];
//        vector<node> foodPosition(30);
//        int mxFood=0;
        int riderCount=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]!='.')
                {
                    riderCount++;
                    bfs(node(i,j), grid[i][j]-'0');
                }
            }
        }
//        for(int i=0; i<n; i++) {
//            for(int j=0; j<m; j++) {
//                printf("%d ", point[i][j]);
//            }
//            printf("\n");
//        }
//        for(ll i=0; i<n; i++)
//            cout<<ara[i]<<endl;
//        printf("riderCount %d\n", riderCount);
        int ans = 1e9;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(cnt[i][j]== riderCount) {
                    ans = min(ans, dist[i][j]);
                }
            }
        }

        if(ans == 1e9)
            ans = -1;

        cout<<"Case "<<tc<<": "<<ans<<endl;


    }



    return 0;
}

