#include <bits/stdc++.h>

using namespace std;

unordered_set<string> uset;
string s;

bool good[200];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
//    cout<<s<<endl;
    string temp;
            cin>>temp;
    for(int i=0; i<26; i++)
        {
            good[i+'a'] = temp[i]-'0';
        }
//    for(int i = 'a'; i<= 'z'; i++)
//        cout<<good[i]<<" "; cout<<endl;
    int k;
    cin>>k;

    int len = s.size();
    for(int i=0; i<len; i++) {
        int cnt = 0;
        int j;
        for(j = i; j<len && cnt+(!good[s[j]] ) <=k; j++) {
            cnt+= (!good[s[j] ]);
//            if(s.substr(i,j).size())
            uset.insert(s.substr(i, j-i+1));
//        printf("i %d j %d cnt %d substr %s\n",i,j,cnt, s.substr(i, j-i+1).c_str());
        }


    }
//    for(unordered_set<string>:: iterator it=uset.begin(); it!= uset.end(); it++) cout<<*it<<","; cout<<endl;

    cout<<uset.size()<<endl;


    return 0;
}
