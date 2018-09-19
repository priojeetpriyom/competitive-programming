#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 60

int inp[100100];
vector<int> vec[MX], ans;




int main()
{
    int n;
    cin>>n;
    int x;
    for(int i=1; i<=n; i++)
    {
        cin>>inp[i];
        vec[inp[i] ].push_back(i);
    }


    for(int i=1;  i<=n; i++)
    {
        int ok=0;
        int mn = 1e9;
        for(int j = inp[i]+1; j<51; j++)
        {

                auto it = lower_bound(vec[j].begin(), vec[j].end(), i);
//                printf("i %d j %d pos %d mn %d\n", i , j, *it, mn);
                if(it != vec[j].end())
                    mn = min(mn, *it);

        }
        ans.push_back( ((mn==1e9)? -1 : inp[mn]) );
    }

    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";



    return 0;
}

