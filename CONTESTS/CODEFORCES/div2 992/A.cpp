#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100

set<int> sset;


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    for(int i=0; i<n; i++) {
        int x;
        cin>>x;
        if(x!=0) {
            sset.insert(x);
        }
    }


    cout<<sset.size()<<endl;


    return 0;
}


