#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 505

string start, endd, s1, s2,s3, temp;
set<string> vis, forbidden;


int n,q;
char addOne(char c) {
    c++;
    if(c>'z')
        return 'a';
    return c;
}
char substractOne(char c) {
    c--;
    if(c<'a')
        return 'z';
    return c;
}

int bfs() {

    queue<pair<string, int> > Q;
    Q.push({start, 0});

    while(!Q.empty()) {
        pair<string, int> cur = Q.front();
        Q.pop();
        string s = cur.first;
        if(vis.find(s)!= vis.end() || forbidden.find(s)!= forbidden.end())
            continue;
        if(s == endd)
            return cur.second;
        vis.insert(s);
//        cout<<s<<endl;

        for(int i=0; i<s.size(); i++) {
            temp = s;
            temp[i] = addOne(temp[i]);
            Q.push({temp, cur.second+1});
            temp[i] = s[i];
            temp[i] = substractOne(temp[i]);
            Q.push({temp, cur.second+1});

        }

    }


    return -1;

}



int main()
{
//    cout<<-13%5;
//    freopen("out.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(false);

    ll t;
    cin>>t;
    cin.ignore();
    for(int tc=1; tc<=t; tc++) {
        vis.clear();
        forbidden.clear();
        cin>>start>>endd;
//        cout<<start<<endl<<endd<<endl;
        cin>>n;
        for(int i=0; i<n; i++) {
            cin>>s1>>s2>>s3;

//        cout<<s1<<endl<<s2<<endl<<s3<<endl;
            temp = "   ";
            for(int p=0; p<s1.size(); p++) {
                    temp[0] = s1[p];
                for(int q=0; q<s2.size(); q++) {
                    temp[1] = s2[q];
                    for(int r=0; r<s3.size(); r++) {
                        temp[2] = s3[r];
                        forbidden.insert(temp);
                    }
                }
            }
        }

        cout<<"Case "<<tc<<": "<<bfs()<<endl;

    }



    return 0;
}

