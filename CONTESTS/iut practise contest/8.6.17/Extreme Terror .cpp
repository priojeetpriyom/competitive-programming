
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


ll ans, give[1000100], take[1000100], prof[1000100];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;

    cin>>t;

    for(int tc=1; tc<=t; tc++) {
        int n, k;
        cin>>n>>k;

        for(int i=0; i<n; i++) cin>>give[i];
        for(int i=0; i<n; i++) cin>>take[i];

        for(int i=0; i<n; i++) {
            prof[i] = take[i]- give[i];
        }
        sort(prof, prof+n);
        ans=0;

        for(int i=0;i<n; i++) {
            if(prof[i]<0 && k) {
                k--; continue;
            }
            ans+= prof[i];

        }
        cout<<"Case "<<tc<<": ";
        if(ans>0) cout<< ans<<endl;
        else cout<<"No Profit"<<endl;
    }


    return 0;
}
