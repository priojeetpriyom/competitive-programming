#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int ara[100100], ara2[100100], vis[100100];
map<int, int> pos;

vector<int> ans[100100];
int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>ara[i];
        ara2[i] = ara[i];
    }

    sort(ara2, ara2+n);


    for(int i=0; i<n; i++) {
        pos[ara2[i]] = i;
    }

    int len_ans=0;
    for(int i=0; i<n; i++) {
        if(vis[i]) continue;
        int ptr = i;
        do {
            ans[len_ans].push_back(ptr+1);
            vis[ptr]=1;
            if(pos[ara[ptr] ] == i) break;
            ptr = pos[ara[ptr]];

        } while(1);
        len_ans++;

    }
//    int f=0;
//    for(int i=0; i<n; i++) {
//        if(vis[i] == 0) {
//            ans[len_ans].push_back(i+1);
//            f=1;
//        }
//
//
//    }
//    len_ans+=f;
    cout<<len_ans<<endl;
    for(int i=0; i<len_ans; i++)
    {
        int len = ans[i].size();
        cout<<len;
        for(int j=0; j<len; j++)
            cout<<" "<<ans[i][j];
        cout<<endl;

    }




    return 0;
}


