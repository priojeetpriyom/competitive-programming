#include <bits/stdc++.h>

using namespace std;
typedef long long ll;





int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int n,m, k;
    int dist=INT_MAX;
    int ara[111];
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++)
        cin>>ara[i];

    for(int i=m+1; i<=n; i++) {
        if(ara[i] && ara[i]<=k) {
            dist = min(dist, 10 * (i-m));
            break;
        }
    }
    for(int i=m-1; i>0; i--) {
        if(ara[i] && ara[i]<=k) {
            dist = min(dist, 10 * (m-i));
            break;
        }
    }
    if(dist == INT_MAX) dist=0;
    cout<<dist;

    return 0;
}


