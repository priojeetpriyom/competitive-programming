#include <bits/stdc++.h>

using namespace std;
typedef long long ll;





int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int n,k;
    cin>>n>>k;

    vector<int> childs, order;
//    childs.push_back(0);
    for(int i=0; i<=n; i++)
    {
        childs.push_back(i);
//        mp[i] = i;
    }
    for(int i=0; i<k; i++)
    {
        int x;
        cin>>x;
        order.push_back(x);
    }
//    printf("childs size %d\n", childs.size());
    int cur=1;
    for(int i=0; i<k; i++) {

        cur += order[i];
        cur  = cur % (childs.size()-1);

        if(!cur) cur = (childs.size() -1 );
//        printf("\ni %d cur %d size %d\n",i, cur, childs.size()-1 );
        cout<<childs[cur]<<" ";
        childs.erase(childs.begin()+cur);
    }

    return 0;
}


