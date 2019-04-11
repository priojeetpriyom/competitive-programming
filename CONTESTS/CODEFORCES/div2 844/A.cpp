#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



int vis[200];

int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int k;
    string s;
    cin>>s>>k;

    if(k>s.size()) cout<<"impossible"<<endl;
    else {
        int cnt=0;
        for(int i=0; i<s.size(); i++)
        if(!vis[s[i]]) {
            vis[s[i]] =1;
            cnt++;
        }

        cout<<max(0, k-cnt)<<endl;
    }


    return 0;
}


