#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



int main()
{
    //    freopen("out.txt", "w", stdout);


    int n,k;

    int x;
    int t;
    cin>>t;

    while(t--)
    {


        cin>>n>>k;
        int mn = 0;
        for(int i=0; i<n; i++)
        {
            cin>>x;
            if(x<=k)
                mn = max(mn, k-x);
        }

        cout<<mn<<endl;
    }

    return 0;
}


