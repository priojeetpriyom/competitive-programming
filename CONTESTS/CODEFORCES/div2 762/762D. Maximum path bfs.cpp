#include <bits/stdc++.h>
using namespace std;

int dist[3] [100100];

 long long cost[3] [100100];
bool visited[3] [100100];

struct node {
    int first, second;
};

void bfs(int n) {
    stack<node> Q;
    int x[] = {1,-1,0,0}, y[] = {0, 0, 1, -1};
    struct node cur, newnode;
    cur.first = cur.second = 0;
    Q.push(cur);

    while(!Q.empty()) {
        cur = Q.top();
        Q.pop();
        int r = cur.first;
        int c = cur.second;

        visited[r] [c] =1;

        for(int i=0; i<4; i++) {
            if(r+y[i] >=0 && r+y[i] <n && c+x[i]>=0 && c+x[i]<n) {
                if(!visited[r+y[i]] [c+x[i] ] && cost[r] [c] + dist[r+y[i]] [c+x[i]] > cost[r+y[i]] [c+x[i]]) {
                     cost[r+y[i]] [c+x[i]] = cost[r] [c] + dist[r+y[i]] [c+x[i]];
                     newnode.first = y[i]+ r;
                     newnode.second = x[i] + c;
                     Q.push(newnode);
                }
            }
        }
        visited[r] [c] =0;

    }
}

int main()
{
//        freopen("myIn.txt", "r", stdin);
//    freopen("myOut.txt", "w", stdout);

    int n;
    cin>>n;

    for(int i=0; i<3; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &dist[i] [j]);
        }
    }
    bfs(n);
    printf("%I64d\n", cost[2] [n-1]);
    return 0;
}









