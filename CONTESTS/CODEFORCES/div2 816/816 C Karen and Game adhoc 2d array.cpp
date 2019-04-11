#include <bits/stdc++.h>

using namespace std;
typedef long long ll;




int grid[555][555], temp_grid[555] [555];


//string to_string(int n)
//{
//    stringstream ss;
//    ss<<n;
//    return ss.str();
//
//}
int n, m;

int del_row(int ara[][555], int print)
{
    int cnt=0;

    for(int i=1; i<=n; i++)
    {
        int mn  = 1e5;
        for(int j=1; j<=m; j++) mn = min(mn, ara[i][j]);

        for(int j=1; j<=m; j++) ara[i][j]-=mn;

        if(mn>0)
        {
            while(mn--)
            {
                if(print)
                {

                    string s = "row ";
                    s+= to_string(i);
                    cout<<s<<endl;
                }
                else cnt++;
            }

        }


    }
    return (print) ? 0:cnt;

}

int del_col(int ara[][555], int print)
{
    int cnt=0;

    for(int j=1; j<=m; j++)
    {
        int mn  = 1e5;
        for(int i=1; i<=n; i++)
            mn = min(mn, ara[i][j]);
//        printf("j %d\n", j);

        for(int i=1; i<=n; i++) ara[i][j]-=mn;
        if(mn>0)
        {
            while(mn--)
            {
                if(print)
                {
                    string s = "col ";
                    s+= to_string(j);
                    cout<<s<<endl;
                }
                else cnt++;
            }

        }

    }

    return (print) ? 0:cnt;

}





int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
//    int n, m;
    int cnt=0;
    cin>>n>>m;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>grid[i][j];
            temp_grid[i][j] = grid[i][j];
        }

    }


    if(n<=m)
    {
        cnt+=del_row(temp_grid, 0);
        cnt+= del_col(temp_grid, 0);
    }
    else
    {
        cnt+= del_col(temp_grid, 0);
        cnt+= del_row(temp_grid, 0);
    }




    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(temp_grid[i][j])
            {
                cout<<-1<<endl;
                return 0;
            }
        }
    }



    cout<<cnt<<endl;




    if(n<=m)
    {
        cnt+=del_row(grid, 1);
        cnt+= del_col(grid, 1);
    }
    else
    {
//        printf("aise\n");
        cnt+= del_col(grid, 1);
        cnt+= del_row(grid, 1);
    }



    return 0;
}


