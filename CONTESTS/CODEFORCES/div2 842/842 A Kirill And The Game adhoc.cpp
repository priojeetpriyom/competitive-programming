#include <bits/stdc++.h>

using namespace std;
typedef long long ll;





int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int l, r, x, y;
    double k;

    cin>>l>>r>>x>>y>>k;
    for(int i = x; i<=y; i++) {
        double temp = i*k;
        if(temp- (int ) temp <= .000000001 ) {
            int j = temp;
            if(j>=l && j<=r) {
                cout<<"YES"<<endl;
                return 0;
            }
        }

    }

    cout<<"NO"<<endl;



    return 0;
}


