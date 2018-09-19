#include<bits/stdc++.h>

using namespace std;
typedef long long ll;


vector<string> pluss, minuss;
set<string> ans;
unordered_map<string, int> prefix;

int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

     string s;
    int n;
    cin>>n;
    cin.ignore();
//    int mx_minus=0;
    char c;
    int len, lim;
    for(int i=0; i<n; i++)
    {
        cin>>c>>s;
        if(c=='+')
        {
            lim = s.size();
            for(int j=1; j<=lim; j++)
                prefix[s.substr(0, j)]=1;
        }
        else
        {
//            cin>>s;
            minuss.push_back(s);
//            mx_minus = max(mx_minus, (int)s.size());
        }
    }

    len  = minuss.size();
    int f=1,ff;
    for(int i=0; i<len; i++)
    {
        ff=0;
        lim = minuss[i].size();
//        string temp;
        for(int j=1; j<=lim; j++)
        {
//            temp += minuss[i][j];
            string temp = minuss[i].substr(0, j);
            if(prefix[ temp]!= 1)
            {
                ans.insert(temp );
                ff=1;
                break;
            }
        }
        if(!ff)
        {
            cout<<-1<<endl;
            return 0;
        }
    }

//
//    if(f)
//    {
        cout<<ans.size()<<endl;
        for(set<string>:: iterator it = ans.begin(); it!= ans.end(); it++ )
            cout<<*it<<"\n";
//    }




    return 0;

}
