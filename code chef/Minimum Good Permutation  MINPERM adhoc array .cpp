#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;




int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    int n;
    while(t--) {
        cin>>n;
        int f=0;
        if(n&1)f=2;
        int i=1;
        for( ; i< n-f; i+=2) {
            cout<<i+1<<" "<<i<<" ";
        }
        if(n&1) {
//            i--;
            cout<<i+1<<" "<<i+2<<" "<<i;

        }
        cout<<endl;
    }

    return 0;
}

