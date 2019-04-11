#include <bits/stdc++.h>

using namespace std;
typedef long long ll;





int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    string grid[11];

    for(int i=0; i<10; i++)
        cin>>grid[i];

    bool yes=false;
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {

            int cnt=0;
            if(5+i<=10)
                for(int k =i; k<min(10,i+5); k++)
                    if(grid[k][j]=='O')
                    {
                        cnt=0;
                        break;
                    }
                    else if(grid[k][j] == 'X') cnt++;
            if(cnt==4)
            {
                yes=true;
            }

            cnt=0;
            if(5+j<=10)
                for(int k =j; k<min(10,j+5); k++)
                    if(grid[i][k]=='O')
                    {
                        cnt=0;
                        break;
                    }
                    else if(grid[i][k] == 'X') cnt++;
            if(cnt==4)
            {
                yes=true;
            }
            cnt=0;
            if(5+ max(i,j)<=10)
                for(int k =0; k<5; k++)
                    if(grid[i+k][j+k]=='O')
                    {
                        cnt=0;
                        break;
                    }
                    else if(grid[i+k][j+k] == 'X') cnt++;
            if(cnt==4)
            {
                yes=true;
            }

            cnt=0;
            if(j-4 >=0 && i+5<=10)
                for(int k =0; k<5; k++)
                    if(grid[i+k][j-k]=='O')
                    {
                        cnt=0;
                        break;
                    }
                    else if(grid[i+k][j-k] == 'X') cnt++;
            if(cnt==4)
            {
                yes=true;
            }




        }
    }

    if(yes) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;



    return 0;
}


