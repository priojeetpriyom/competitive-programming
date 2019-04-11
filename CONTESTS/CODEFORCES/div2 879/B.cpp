#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100

ll ara[1000];


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll k;
    cin>>n>>k;

    ll mx=0;
    int mx_pos;
    for(int i=1; i<=n; i++)
    {
        cin>>ara[i];

        if(ara[i] > mx)
        {
            mx = ara[i];
            mx_pos = i;
        }
    }

//        if(k <= (mx_pos-1)) {
    int cnt=0;
//    printf("mx %lld mx_pos %d\n", mx, mx_pos);
    ll cur = ara[1];
    for(int i=2; i< mx_pos; i++)
    {
//        printf("i %d\n", i);
        if(cur > ara[i])
        {
            cnt++;
            if(cnt==k)
            {
                cout<<cur<<endl;
                return 0;
            }
        }
        else
        {
            cnt=1;
            cur = ara[i];
        }
    }

//    }

    cout<<ara[mx_pos]<<endl;



    return 0;
}


