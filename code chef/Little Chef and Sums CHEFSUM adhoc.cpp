#include <bits/stdc++.h>

using namespace std;
typedef long long ll;





int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {

        int mn=1e9, idx=1, n;

        int x;
        cin>>n;
        for(int i=1; i<=n; i++)
        {
            cin>>x;
            if(x<mn)
            {
                idx = i;
                mn = x;
            }
        }
        cout<<idx<<endl;
    }



    return 0;
}


