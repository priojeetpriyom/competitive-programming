#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



map<ll, int> mp;


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    ll sum=0;
    ll x;
    for(int i=1; i<=n; i++)
    {
        cin>>x;
        sum+= x;
        if(x&1)
            mp[x]++;
    }
    map<ll, int> :: iterator it;

    int f=1;
    if(sum%2==0) {
        x=0;
        for(it = mp.begin(); it!= mp.end(); it++) {
//            if( (it->second)%2==0)
               x+= (it->second);
        }
        if(x>0) f=1;
        else f=0;

    }

    if(f) cout<<"First"<<endl;
    else cout<<"Second"<<endl;





    return 0;
}


