#include <bits/stdc++.h>

using namespace std;
typedef long long ll;




int main()
{


//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    vector<int> vec;

    int t,n=100;

    set<int> sset;

    for(int i=1; i<=500; i++) sset.insert(i);
    int x=1;

    while(n--) {
         while(sset.find(x) == sset.end()) x++;

        vec.push_back(x);

        sset.erase(sset.find(x));


        for(int i = vec.size()-2; i>=0; i--) {
            if(sset.find(x+vec[i]) != sset.end())
                sset.erase(sset.find(x+ vec[i]));
        }

    }

    cin>>t;

    while(t--) {
        cin>>n;

        for(int i=0; i<n; i++)
            cout<<vec[i]<<" ";
        cout<<endl;
    }



    return 0;
}





