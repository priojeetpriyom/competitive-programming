#include <bits/stdc++.h>
using namespace std;
#define ll long long
int par[1000];
queue<char> Q;

ll ara[200100];
int mark[200100];

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int  n;
    string s1, s2;
    cin>>n;

    for(int i=1; i<=n; i++)
    {

        cin>>ara[i];
        ara[n+i] = ara[i];
    }
    ll s,f;
    cin>>s>>f;

    for(int i = 1; i<=n+n; i++)
        ara[i]+= ara[i-1];


    ll mx=0, idx=0;

    for(int i=n; i<=n; i++)
    {
        if( ara[i+(f-s)-1] -ara[ i-1]>mx)
        {
            idx = i+(f-s)-1;
            mx = ara[i+(f-s)-1] -ara[ i-1];
            printf("i %d mx %d\n", i, mx);
        }
        //   cout<<"i "<<i<<" l "<<i+s-1<< " r "<<i+max(0LL, f-1-s)<<" ans "<<ara[i+max(0LL, f-1-s)] - ara[i-1]<<endl;
        // cout<<"i "<<i<<" ara_l "<<ara[i+s-1]<< " ara_r "<<ara[i+max(0LL, f-1-s)]<<endl<<endl;

    }

    cout<<idx<<endl;


    return 0;
}
