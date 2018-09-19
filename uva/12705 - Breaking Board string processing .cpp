#include <bits/stdc++.h>

using namespace std;


multiset <int > sset, temp;
int freq[100];
string s;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int i=1; i<=6; i++) {
        for(int j=1; j<=6; j++) {
            sset.insert(i+j);
        }
    }


    int t;
    cin>>t;



    cin.ignore();
    for(int tc=1; tc<=t; tc++) {
        getline(cin, s);
//        cout<<s<<endl;
        memset(freq, 0, sizeof freq);
        int len = s.size();
        for(int i=0; i<len; i++) {
            if(s[i]!= ' ')
                freq[toupper(s[i])- '0']++;
        }
        temp = sset;
        int ans=0;
        sort(freq, freq+ 100);
        for(int i=99; i>=0; i--) {
            if(freq[i]) {
                ans+= (freq[i] * (*temp.begin()));
                temp.erase(temp.begin());
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}

