#include <bits/stdc++.h>

using namespace std;
typedef long long ll;





int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int n,k, x;
    cin>>n>>k;
    double ans=0;
    int cnt=0;
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        ans+=x;
    }



    while(round(ans/ (n+cnt) )<k) {
        ans+=k;
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}


