#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 3030


multiset<int>vec[MX];
multiset<pair<int, int> > sset;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, h, a, b, t1,h1,t2,h2, k;



    cin>>n>>h>>a>>b>>k;

    while(k--) {
        cin>>t1>>h1>>t2>>h2;
        int ans=0;
        if(t1==t2)
            ans = abs(h1-h2);
        else
        {
//            if(h1<a || h1>b) {
//                if(h2<a || h2>b) {
//
//                } else {
//
//                }
//            }
            if(h1>=a && h1<=b) {
                ans = min(abs(h2-h1) , abs(h2-h1));
            } else
                ans+= min(abs(h1-a)+ abs(h2-a) , abs(h1-b)+ abs(h2-b));
            ans+= abs(t2-t1);
//            ans+= min();
        }
        cout<<ans<<endl;
    }


    return 0;
}

