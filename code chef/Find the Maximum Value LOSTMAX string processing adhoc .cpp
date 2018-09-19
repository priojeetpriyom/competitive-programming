#include<bits/stdc++.h>

using namespace std;
typedef long long ll;




int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false); cin.tie(0);

    int t;
    cin>>t;
    cin.ignore();
    for(int tc=1; tc<=t; tc++)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);
//        ss.str(ss);
        int cnt=0, num;
        int mx1=0, mx2=0;
//        unordered_multiset<int> sset;
        while(ss>>num) {
//            ss>>num;
//            cout<<"n "<<num<<endl;
//            sset.insert(num);
            if(num > mx1) {
                mx2 = mx1;
                mx1=num;
            }
            else if(num>mx2) mx2= num;
            cnt++;
        }
//        cout<<"mx1 "<<mx1<<" mx2 "<<mx2<<endl;
        int ans = mx1;
        if(cnt-1 == mx1) ans = mx2;
//        sset.erase(sset.find(sset.size()-1));
        cout<<ans<<endl;

    }


    return 0;

}

