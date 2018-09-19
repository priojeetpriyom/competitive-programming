#include<bits/stdc++.h>
using namespace std;

//int ara[1010], len, dp[1010] [32867];
int connection[10] [10], visited[10] [10];
vector<int> path;
bool allVisited() {
    for(int i=1; i<=5; i++)
        for(int j=1; j<=5; j++)
        if(connection[i][j] && !visited[i] [j])
            return false;
    return true;
}
int rec(int cur) {

    if(allVisited())
    {
        int len = path.size();
        for(int i=0; i<len; i++)
            printf("%d",path[i]);
        printf("\n");
        return 0;
    }

//    printf("rec coler\n");
    for(int i=1; i<=5; i++) {
        if(connection[cur] [i] && !visited[cur] [i]) {
            visited[cur] [i] = visited[i] [cur] = 1;
            path.push_back(i);
            rec(i);
            path.pop_back();
            visited[cur] [i] = visited[i] [cur] = 0;
        }
    }
}

int main()
{
//    freopen("myIn.txt", "r", stdin);
//    freopen("myOut.txt", "w", stdout);

    connection[1][2] = connection[1][3] = connection[1][5] = connection[2][1] = connection[2][3] = connection[2][5] = connection[3][1] = connection[3][2] = connection[3][4] = connection[3][5] = connection[4][3] = connection[4][5] = connection[5][1] = connection[5][2] = connection[5][3] = connection[5][4] = 1;
    path.push_back(1);
    memset(visited, 0 , sizeof visited);
    rec(1);
}


