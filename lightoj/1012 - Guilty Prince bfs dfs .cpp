#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

string grid[201];
int vis[201] [201];



    int n, m;
int dfs(int r, int c) {
//    printf("r %d c %d\n", r,c);
    if(r==n || c==m || r<0 || c<0 || vis[r][c] || grid[r][c]== '#') return 0;
    vis[r][c]=1;
    return max(dfs(r+1, c) + dfs(r-1, c) + dfs(r, c+1) + dfs(r, c-1), 0)+1;

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
        memset(vis, 0, sizeof vis);
        cin>>m>>n;
        for(int i=0; i<n; i++)
            cin>>grid[i];

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == '@') {
                    cout<<"Case "<<tc<<": "<<dfs(i,j)<<endl;
                    break;
                }
            }
        }
    }


    return 0;

}

