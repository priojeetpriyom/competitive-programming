#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


struct node{
    int floor, flat;
    node(int a, int b) {
        flat = a;
        floor=b;
    }
};

int by(int a, int b) {
    return (a/b)+ (a%b!=0);
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n, m,a,b;
    cin>>n>>m;
    vector<node >vec;
    int mx=0;
    for(int i=0; i<m; i++) {
        cin>>a>>b;
        mx = max(mx, a);
        vec.push_back(node(a,b) );
    }
    int cnt=0, ans=0;

    for(int i=1; i<=100; i++)
    {
        int temp=0;
        for(int j=0; j<vec.size(); j++) {
            if( by(vec[j].flat, i) == vec[j].floor ) {
                temp++;
            }
//            cout<<"i "<<i<<" j "<<j<<" temp "<<temp<<endl;
        }
        if(temp ==  vec.size()) {
//            cout<<"div "<<i<<endl;
            cnt++;
            ans = i;
            if(cnt>1) break;
        }


    }
//    cout<<"cnt "<<cnt<<endl;
    if(cnt==1) {
        cout<<by(n, ans)<<endl;
    } else cout<<-1<<endl;


    return 0;
}


