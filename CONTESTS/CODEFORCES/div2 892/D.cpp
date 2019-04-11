#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100

map<ll, int> mp;
int n;
ll ara[22], x;


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    int hasZero=0;
    for(int i=0; i<n; i++) {
        cin>>x;
        ara[i]=x;
    }
    if(n== 1)
        return cout<<-1<<endl, 0;
//    bool ok = true;
//    vector<ll> vec(ara, ara+n);
//    sort(ara, ara+n);

    cout<<ara[n-1];

    for(int i=0; i<n-1; i++)
        cout<<" "<<ara[i];



    return 0;
}


