#include <bits/stdc++.h>

using namespace std;
typedef long long ll;





int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n, k;
    cin>>n>>k;

    ll sum=0;
    int x;
    for(int i=0; i<n; i++) {
        cin>>x;

        sum += ((x+k-1)/k);
    }
    cout<<(sum+1)/2;
    return 0;
}


