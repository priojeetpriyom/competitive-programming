#include <bits/stdc++.h>
using namespace std;
int n,m;
char str [100] [100];
bool visited[100] [100];
int mx;

void visit(int i, int j, int cnt)
{

    if(visited[i][j] || str[i][j] != 'G')
        return;
    visited[i][j] = true;
    printf("i %d j %d\n", i, j);
    if(i>=n || j>=m || i<0 || j<0)
    {
        mx=  max(mx, cnt-1);
        return;
    }

    visit(i+1, j, cnt+1);
    visit(i+1, j-1, cnt+1);
    visit(i, j-1, cnt+1);
    visit(i-1, j-1, cnt+1);
    visit(i-1, j, cnt+1);
    visit(i-1, j+1, cnt+1);
    visit(i, j+1, cnt+1);
    visit(i+1, j+1, cnt+1);

}


int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);
    int t;
    scanf("%d", &t);

    for(int tcase = 1; tcase<=t; tcase++)
    {
        scanf("%d %d", &n, &m);

        for(int i=0; i<n; i++)
            scanf("\n%s", str[i]);
        memset(visited, 0, sizeof(visited));
        mx = INT_MIN;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!visited[i][j])
                {
                    visit(i,j, 0);
                }
            }
        }
        printf("Case %d: %d\n", tcase, mx);
    }


    return 0;
}

