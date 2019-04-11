#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int len;
map<string, pair<int, int> > mp;
string s;
 map<string, int> dup;
void calc(int pos) {
    string temp;
    temp = s.substr(pos+1, len-pos);
    for(int i = 0; i<=pos; i++)
        temp+= s[i];

    pair<int, int> p = mp[temp];
    if(dup.find(temp) != dup.end())
        return;
    else
        dup[temp]++;
    p.first++;

    p.second += pos+1;
    mp[temp] =p;
//    cout<<temp<<endl;
//    return temp;
}



int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n;
    cin>>n;
    int x = n;
    while(n-- ) {
        cin>>s;
        len = s.size();
        for(int i=-1; i<len; i++) {

            calc(i);

        }
        dup.clear();
    }
    int ans = 1e9;
    for(map<string, pair<int, int> >:: iterator it = mp.begin(); it!= mp.end(); it++) {
        if(it->second.first == x) {
            ans = min(ans, it->second.second);
        }
    }
    if(ans == 1e9) cout<<-1;
    else
        cout<<ans;

    return 0;
}


