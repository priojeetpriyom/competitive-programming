/*
    algo:
    idea:

*/
#include <iostream>

#define LIM 1001
using namespace std;

int conn[LIM] [LIM], vis[LIM];

void bfs(int start, int n) {
    int q[LIM], qq[LIM];
    q[0] = qq[0]=0;
    q[++q[0]] = start;
    vis[start]=1;

    while(q[0]) {
        qq[0]=0;
        for(int i=1; i<= q[0]; i++){
            int u = q[i];
            cout<<"u "<<u<<endl;
            for(int v=1; v<=n; v++) {
                if(conn[u][v] && !vis[v]) {
                    vis[v]=1;
                    qq[++qq[0]] = v;
                }
            }
        }
        swap(q,qq);

    }
}

int main()
{
//    FAST_READ

    conn[1][2] = 1;
    conn[1][3] = 1;
    conn[2][4] = 1;
    conn[2][5] = 1;
    conn[3][6] = 1;
    conn[3][7] = 1;
    // conn[][] = 1;
    // conn[][] = 1;\

    bfs(1,7);

    return 0;
}
