#include <bits/stdc++.h>

using namespace std;
typedef long long ll;





int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n,m;
    cin>>n>>m;
    bool ans = false;
    for(int i=0; i<m; i++) {
        int k,x;
        cin>>k;
        map<int, int> mp;
        bool xxx  = true;
        for(int i=0; i<k; i++) {
            cin>>x;
            if(!ans) {
                mp[x]++;
                if(mp[x] >= 1 && mp[-x]>=1)
                    xxx= false;
            }

        }if(xxx) ans = true;
    }

    if(ans)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}


