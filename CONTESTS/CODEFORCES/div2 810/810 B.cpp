#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


vector<pair<ll, ll> > mn(100100);
vector<ll> k(100100), ii(100100);


bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
return a.first >b.first;
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n, f;

    ll ans=0;

    cin>>n>>f;

    for(int i=0; i<n; i++) {
        scanf("%I64d %I64d", &k[i], &ii[i]);
        mn[i] = make_pair(min(k[i]<<1, ii[i] ) - min(k[i], ii[i]), i);
    }

    sort(mn.begin(), mn.begin()+n, cmp);

    for(int i=0; i<f; i++) {
        ans += min(ii[mn[i].second], (k[ mn[i].second ]<<1) );

    }

    for(int i=f; i<n; i++) ans+= min(ii[mn[i].second], (k[ mn[i].second ]) );

    cout<<ans<<endl;

    return 0;
}


