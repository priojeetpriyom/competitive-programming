#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100




int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    int t;
    cin>>t;

    while(t--) {

        int n;
        cin>>n;

        int ans=0;
        unordered_map<int, int> mp;
        while(n--) {
            int x;
            cin>>x;
            if(mp.count(x))
                ans++;
            else
                mp[x]=1;
        }
        printf("%d\n", ans);
    }



    return 0;
}


