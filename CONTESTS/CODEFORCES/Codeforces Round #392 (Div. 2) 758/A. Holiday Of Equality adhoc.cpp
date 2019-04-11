#include <bits/stdc++.h>
using namespace std;

int main()
{
//        freopen("myIn.txt", "r", stdin);
//    freopen("myOut.txt", "w", stdout);

    int n;
    int ara[110];
    cin>>n;
    int mx = INT_MIN, ans=0;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &ara[i]);
        mx = max(mx, ara[i]);
    }
    for(int i=0; i<n; i++) {
        ans += (mx-ara[i]);
    }
    cout<<ans;
    return 0;
}






