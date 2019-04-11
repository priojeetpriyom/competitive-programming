#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


vector<pair<int, int> > vec;
vector<string> str;

string ans;
int main()
{
//    ans.reserve((1000100));
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k, x;
    string s;

    cin>>n;
    cin.ignore();
    int mx=0;
    for(int i=0; i<n; i++) {
        cin>>s;
        cin>>k;
        int x;
        str.push_back(s);
        for(int j=0; j<k; j++) {
            cin>>x;
            vec.push_back(make_pair(x, i));
            mx = max(mx, (int)s.size()+x-1);
        }
//        cout<<"i "<<i<<endl;
    }
    sort(vec.begin(), vec.end());
    for(int i=0; i<=mx; i++) {
        ans+='a';
    }

//    cout<<"ans_size "<<ans.size()<<" mx "<<mx<<endl;
    int prev =1;

    int xx = vec.size();
    for(int i=0; i<xx; i++) {
//            cout<<"prev "<<prev<<" i "<<vec[i].first<<" "<<vec[i].second<<endl;

        if(vec[i].first+ (int) str[vec[i].second].size()-1 >= prev) {
            prev = max(prev, vec[i].first);
            int common = prev - vec[i].first ;
            int len = str[vec[i].second].size();
            for(int j=common; j<len; j++)
                ans[prev++] = str[vec[i].second] [j];

        }




    }



//    cout<<"aise"<<endl;




//    }

    cout<< ans.substr(1, mx+1)<<endl;


    return 0;
}
