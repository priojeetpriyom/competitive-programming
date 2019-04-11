#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct node
{
    ll z_r=0, z_c=0;
    ll o_r=0, o_c=0;

};
ll ara[100] [100];
node arr[100][100];




int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);


    ll n, m;

    cin>>n>>m;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin>>ara[i][j];

    ll ans=n*m;

    for(int i=1; i<=max(n,m ); i++)
    {
        int cnt=0;
        if(i<=n)
        for(int j=1; j<=m; j++)
        {
            if(ara[i][j]==1) cnt++;
        }
        if(cnt)
            arr[i][i].o_r = cnt;
        cnt^=cnt;
        if(i>m) continue;
        for(int j=1; j<=n; j++)
        {
            if(ara[j][i]==1) cnt++;
        }
        if(cnt)
            arr[i][i].o_c = cnt;

    }
    for(int i=1; i<=max(n, m); i++)
    {
        int cnt=0;
        if(i<=n)
        for(int j=1; j<=m; j++)
        {
            if(ara[i][j]==0) cnt++;
        }
        if(cnt)
            arr[i][i].z_r = cnt;
        cnt^=cnt;
        if(i>m) continue;
        for(int j=1; j<=n; j++)
        {
            if(ara[j][i]==0) cnt++;
        }
        if(cnt)
            arr[i][i].z_c = cnt;

    }

    for(int i=1; i<=max(n, m); i++) {
        node & a = arr[i][i];
        if(a.o_c) {
            ans+= ( (1LL<<a.o_c) - a.o_c-1 );
        }
        if(a.o_r) {
            ans+= ( (1LL<<a.o_r) - a.o_r- 1 );
        }
        if(a.z_c) {
            ans+= ( (1LL<<a.z_c) - a.z_c-1 );
        }
        if(a.z_r) {
            ans+= ( (1LL<<a.z_r) - a.z_r- 1 );
        }
//        cout<<"i "<<i<<" o_c "<<a.o_c<<" o_r "<<a.o_r<<" z_c "<<a.z_c<<" z_r "<<a.z_r<<endl;
//        cout<<"i "<<i<<" ans "<<ans<<endl;
    }

    cout<<ans<<endl;


    return 0;
}


