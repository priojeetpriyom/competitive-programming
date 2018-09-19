#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 55

struct node {
    int r, c;
    int dist;
    node(int rr=0, int cc=0, int dd = 0) {
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

int n;
string grid[15];

int vis[15] [15];

int bfs(node start, char endd) {

    queue<node> Q;
    Q.push(start);
    int cnt = endd - 'A';
    while(!Q.empty()) {
        node cur = Q.front();
        Q.pop();
        int & r = cur.r;
        int & c = cur.c;
        if(r>=n || r<0 || c>=n || c<0 || vis[r][c]==cnt || grid[r][c]=='#')
            continue;
        vis[r][c] = cnt;
        if(grid[r][c] == endd)
            return cur.dist;
        if(grid[r][c]>='A' && grid[r][c]<='Z') {
//            printf("%d %d %c\n",r, c, grid[r][c]);
            if(grid[r][c]> endd)
                continue;
//        printf("continue dhuke nai\n");
        }

        Q.push(node(r+1, c, cur.dist+1));
        Q.push(node(r-1, c, cur.dist+1));
        Q.push(node(r, c+1, cur.dist+1));
        Q.push(node(r, c-1, cur.dist+1));
    }

    return -1;

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
        memset(vis, -1, sizeof vis);
        cin>>n;
        for(ll i=0; i<n; i++)
            cin>>grid[i];
        vector<node> foodPosition(30);
        int mxFood=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]>='A' && grid[i][j]<='Z') {
                    foodPosition[grid[i][j]-'A'] = node(i, j);
                    mxFood = max(mxFood, grid[i][j]-'A');
                }
            }
        }
//        for(ll i=0; i<n; i++)
//            cout<<ara[i]<<endl;
        cout<<"Case "<<tc<<": ";

        bool ok = true;
        int dist=0;

        for(int i=0; i<mxFood; i++) {
            int ret = bfs(foodPosition[i], i+1+'A');
            if(ret==-1)
            {
                dist=-1;
                break;
            }
            dist+=ret;
        }
        if(dist== -1)
            cout<<"Impossible"<<endl;
        else
            cout<<dist<<endl;

//        cout<<a<<","<<b<<","<<c<<endl;
//        if(ret==0 || ret==tot)
//        else
//            cout<<"Case "<<tc<<": "<<ret<<"/"<<tot<<endl;
    }



    return 0;
}

