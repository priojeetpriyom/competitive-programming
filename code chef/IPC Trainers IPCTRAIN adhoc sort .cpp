#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

multiset< pair<ll, ll> > sset;
vector<pair<ll, pair<ll, ll> > > vec;
int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);  cin.tie(0);


    int t;
    cin>>t;


    while(t--) {
        vec.clear();
        sset.clear();
        int n;
        ll day;
        cin>>n>>day;
        for(int i=0; i<n; i++) {
            ll si,di,ti;
            cin>>di>>ti>>si;
             vec.push_back(make_pair(di, make_pair(si, ti)));
        }
        sort(vec.begin(), vec.end());

        int j=0;
        for(ll i=1; i<=day; i++) {

            while(vec[j].first<=i && j<n) {
                sset.insert(vec[j].second);
                j++;
            }

            if(sset.size()) {
                pair<ll, ll> p = (* (sset.rbegin()));
                sset.erase(--sset.end());
                p.second-=1;
                if( p.second !=0 ) {

                    sset.insert(p);
                }
            }


        }
        ll ans=0;
        while(sset.size()) {
            pair<ll, ll> p = (* (sset.rbegin()));
            sset.erase(--sset.end());
            ans += (p.first * p.second);
        }

        cout<<ans<<endl;

    }


    return 0;

}

