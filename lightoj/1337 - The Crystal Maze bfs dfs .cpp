#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 505

struct node {
    int r, c;
//    int dist;
    node(int rr=0, int cc=0, int dd = 0) {
        r = rr;
        c = cc;
//        dist =dd;
    }
//    node(int rr, int cc, int dd) {
//        r = rr;
//        c = cc;
//        dist = dd;
//    }
};

int n, m ,q;
string grid[MX];

int point[MX] [MX];

int bfs(node start) {

    queue<node> Q;
    Q.push(start);
    int cnt = 0;
    vector<node> path;
    while(!Q.empty()) {
        node cur = Q.front();
        Q.pop();
        int & r = cur.r;
        int & c = cur.c;
        if(point[r][c]>=0 || grid[r][c]=='#')
            continue;
        path.push_back(cur);
        point[r][c]=0;
        if(grid[r][c]== 'C')
            cnt++;
        if(r+1 <n)
        Q.push(node(r+1, c));
        if(r>0)
        Q.push(node(r-1, c));
        if(c+1<m)
        Q.push(node(r, c+1));
        if(c>0)
        Q.push(node(r, c-1));
    }

    for(int i=0; i<path.size(); i++)
        point[path[i].r ] [path[i].c ] = cnt;

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
    for(int tc=1; tc<=t; tc++) {
        memset(point, -1, sizeof point);
        cin>>n>>m>>q;
        for(ll i=0; i<n; i++)
            cin>>grid[i];
//        vector<node> foodPosition(30);
//        int mxFood=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]!='#' && point[i][j]==-1) {
                    bfs(node(i,j));
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
        cout<<"Case "<<tc<<":"<<endl;

        while(q--) {
            int u, v;
            cin>>u>>v;
            cout<<point[u-1][v-1]<<endl;
        }

 //        cout<<a<<","<<b<<","<<c<<endl;
//        if(ret==0 || ret==tot)
//        else
//            cout<<"Case "<<tc<<": "<<ret<<"/"<<tot<<endl;
    }



    return 0;
}

