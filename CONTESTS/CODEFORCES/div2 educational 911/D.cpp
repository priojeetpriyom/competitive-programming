#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 1511
int ara[1511];

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    int n,m;
    scanf("%d", &n);

    for(int i=1; i<=n; i++)
        cin>>ara[i];
    int cnt=0;
    for(int i=1; i<=n; i++) {
        for(int j = i+1; j<=n; j++) {
            if(ara[i]>ara[j]) {
              cnt++;
            }
        }
    }
    int ans = (cnt&1);
//    cout<<cnt<<" "<<ans<<endl;
    int l, r;
    scanf("%d", &m);

    while(m--) {
        cin>> l>>r;

        if(((r-l+1)/2)&1)
            ans ^=1;

        if(ans==1)
            cout<<"odd"<<endl;
        else
            cout<<"even"<<endl;
    }


    return 0;
}


