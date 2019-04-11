#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 2020

char grid[MX] [MX];
int cumC[MX] [MX],cumR[MX] [MX];


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin>>n>>m>>k;

    for(int i=1; i<=n; i++)
    {

        for(int j=1; j<=m; j++)
        {
            cin>>grid[i][j];
        }
    }

    for(int j=1; j<=m; j++)
    {
        for(int i=n; i>0; i--)
        {

            if(grid[i][j]=='.')
            {
                cumR[i][j] = cumR[i+1][j]+1;
            }
        }
    }
    for(int i=1; i<=n; i++)
    {

        for(int j=m; j>0; j--)
        {
            if(grid[i][j] == '.')
                cumC[i][j] = cumC[i][j+1] +1;
            }
    }

    int ans=0;
    for(int i=1; i<=n; i++)
    {

        for(int j=1; j<=m; j++)
        {
            if(grid[i][j]=='.') {
                if(cumC[i][j] >=k)
                    ans++;
                if(k!=1 && cumR[i][j] >=k)
                    ans++;
            }
//            printf("i %d j %d ans %d\n", i,j, ans);
        }
    }
//    if(ans> n*m)
//        ans = n*m;

    cout<<ans<<endl;



    return 0;
}


