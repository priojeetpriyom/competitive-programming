#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 15
int ara[11];
ll ans[100100];

int main()
{
//    cout<<-13%5;
//    freopen("out.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    int n;
    cin>>n;
    ll sum=0, x;
    ll mx=0;
    for(int i=1; i<=n; i++)
        cin>>x, sum+=x, mx = max(mx, x);
    n--;
    cout<<max(mx, sum/n+ (sum%n!=0) )<<endl;


    return 0;
}
