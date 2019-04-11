#include <bits/stdc++.h>

using namespace std;
typedef long long ll;





int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    string s[111];
    cin>>n>>m;

    cin.ignore();


    for(int i=0; i<n; i++)
    {
        cin>>s[i];
    }
//    cout<<"aise"<<endl;
    int  mx= 0;
    int mn_x=200, mn_y=200, mx_x=0, mx_y=0;
    int flag=1;
    for(int i=0; i<n; i++)
    {
//        prev= -1;
        for(int j=0; j<m; j++)
        {
            if(s[i][j]=='B')
            {
                flag=0;
                mx_x = max(mx_x, j);
                mx_y = max(mx_y, i);
                mn_x = min(mn_x, j);
                mn_y = min(mn_y, i);
            }


        }


    }
    mx = max(mx_x-mn_x, mx_y-mn_y) +1;

    if(mn_x+mx >m) {
        mn_x -= (mn_x + mx-m);
    }
    if(mn_y+mx > n ) {
        mn_y -= (mn_y + mx- n);
    }
//    cout<<"mx "<<mx<<endl;
    if(mx<=1) {
        cout<<flag<<endl;
        return 0;

    }
    if(mx>n || mx> m) {
        cout<<-1<<endl;
        return 0;
    }



    int ans=0;

    for(int i = mn_y; i<mn_y+mx; i++) {
        for(int j = mn_x; j<mn_x+mx; j++) {
            if(s[i][j] =='W')ans++;
        }

    }
//    cout<<"mn_x "<<mn_x<<" mn_y "<<mn_y<<" mx_x "<<mx_x<<"mx_y "<<mx_y<<endl;


    cout<<ans<<endl;







    return 0;
}




