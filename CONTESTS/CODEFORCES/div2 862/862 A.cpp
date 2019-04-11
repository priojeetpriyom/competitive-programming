#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


    int ara[111];



int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int k, x;
    cin>>n>>k;
    int op = k;
    for(int i=1; i<=n; i++) {
        cin>>x;
        ara[x]=1;
    }

    int ans=0;
    for(int i=0; i<k; i++) {
        if(!ara[i]) ans++;
    }
    if(ara[k]) ans++;

    cout<<ans<<endl;


    return 0;
}


