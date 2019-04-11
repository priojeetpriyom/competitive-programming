#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100

int mp[15][15];

    int n;


bool possible(int num) {


    vector<int> vec;
    while(num>0) {
       vec.push_back(num%10);
        num/=10;
    }
    int cnt[14] = {0};

    for(int i=0; i<vec.size(); i++) {
        for(int j=1; j<=n; j++) {
            if(mp[j][ vec[i] ]) {
                cnt[ vec[i] ]++;
            }
        }
    }
    int ans=0;
    int vis[10] = {0};
    for(int i=1; i<=100; i++) {
        for(int j=0; j<vec.size(); j++) {
            if(cnt[ vec[j] ]==i) {
                for(int k=1; k<=n; k++) {
                    if(!vis[k] && mp[k] [ vec[j] ]) {
                        vis[k]=1;
                        ans++;
                        break;
                    }
                }
            }
        }
    }



    return ans==vec.size();




}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin>>n;

    for(int i=1; i<=n; i++) {
        int ara[13] = {0};
        for(int j=0; j<6; j++)
        {
            int x;
            cin>>x;
            mp[i][x]=1;
        }
    }

    int ans=0;
    while(possible(ans+1))
        ans++;

//    if(!ans)
        cout<<ans<<endl;

    return 0;
}


