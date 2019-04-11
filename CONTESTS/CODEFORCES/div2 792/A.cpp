#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



int ara[200100];

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n;
    cin>>n;
    int mn= INT_MAX;
    map<int, int> mp;
    for(int i=0; i<n; i++)
    {
        cin>>ara[i];
        mp[ara[i]] = 1;
    }
    sort(ara, ara+n);

    for(int i=1; i<n; i++)
        mn = min(mn, abs(ara[i] - ara[i-1]));
    int cnt=0;
    for(int i=0; i<n; i++) {
        if(mp.count(ara[i]-mn))
            cnt++;
    }

    cout<<mn<<" "<<cnt;
    return 0;
}


