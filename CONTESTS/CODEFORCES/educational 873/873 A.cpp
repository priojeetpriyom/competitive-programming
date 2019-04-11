#include <bits/stdc++.h>

using namespace std;
typedef long long ll;





int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, x;
    cin>>n>>k>>x;
    int a, sum=0;
    for(int i=1; i<=n; i++)
    {
        cin>>a;
        sum+=a;
        if(i >= n-k+1) {
            sum-=(a-x);
        }
    }


    cout<<sum<<endl;


    return 0;
}


