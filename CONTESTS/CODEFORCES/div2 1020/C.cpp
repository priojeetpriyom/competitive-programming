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

    int n, m;
    cin>>n>>m;
    int c, p;
    int ucnt=0;
    int mx=0, mxid=0;
    for(int i=0; i<n;i++) {
        cin>>p>>c;
        if(p==1) {
            ucnt++;
            continue;
        }
        vec[p].insert(c);
        sset.insert(make_pair(c, p));
    }

    int cost=1e9+1;

    for(int i=1; i<=m; i++) {

        if(vec[i].size()>mx) {
            mx = vec[i].size();
            mxid = i;
            cost = *(vec[i].begin());

        } else if(vec[i].size()==mx && *(vec[i].begin())<cost) {
            mx = vec[i].size();
            mxid = i;
            cost = *(vec[i].begin());
        }
    }

    ll ans=0;

    while(ucnt<=mx) {
//        cout<<"ucnt "<<ucnt<<" mx "<<mx<<" mxid "<<mxid<<" mx_low_cost "<<(*(vec[mxid].begin()))<< endl;
        int mn1 = (*(sset.begin())).first;
        int mn2 = (*(++sset.begin())).first;
        int mnid1 = (*(sset.begin())).second;
        int mnid2 = (*(++sset.begin())).second;

//        cout<<"mn1 "<<mn1<<" mn2 "<<mn2<<endl;

        if(ucnt==mx) {
            ans+= mn1;
            break;
        } else if(mn1+mn2> (*(vec[mxid].begin())) ) {
            ans+= *(vec[mxid].begin());
            ucnt++;
            sset.erase(sset.find(make_pair(*(vec[mxid].begin()), mxid)));
            vec[mxid].erase(vec[mxid].begin());
        }else {
            ans+= mn1;
            ucnt+=1;
            vec[mnid1].erase(vec[mnid1].begin());
//            vec[mn2].erase(vec[mnid2].begin());
            sset.erase(sset.begin());
//            sset.erase(sset.begin());
        }
//        cout<<"aise"<<endl;
        mx=0;
        cost = 1e9+1;
        for(int i=1; i<=m; i++) {

            if(vec[i].size()>mx) {
                mx = vec[i].size();
                mxid = i;
                cost = *(vec[i].begin());
            } else if(vec[i].size()==mx && *(vec[i].begin())<cost) {
                mx = vec[i].size();
                mxid = i;
                cost = *(vec[i].begin());
            }
        }
    }

    cout<<ans<<endl;


    return 0;
}


