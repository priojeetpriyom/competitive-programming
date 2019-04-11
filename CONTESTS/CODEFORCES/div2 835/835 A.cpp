#include <bits/stdc++.h>

using namespace std;
typedef long long ll;





int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);


    int len, v1, v2, t1, t2;

    cin>>len>>v1>>v2>>t1>>t2;

    int cost1 = (len*v1) +t1+t1;
    int cost2 = (len*v2) + t2+t2;
    if(cost1 == cost2) cout<<"Friendship"<<endl;
    else if(cost1 < cost2) cout<<"First"<<endl;
    else cout<<"Second"<<endl;


    return 0;
}


