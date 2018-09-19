#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

map<string, set<int> > mp;
map<string, int> mx_cnt;

string create(string s)
{
    int x=0;
//    if(mp.find(s) == mp.end()) {
    mp[s];
    mx_cnt[s];
    set<int> &sset = mp[s];
    if(!sset.size()) {
        sset.insert(mx_cnt[s]);
        mx_cnt[s]++;
    }
//    }
    x = (*sset.begin() );
    sset.erase(sset.begin());
//    sset.insert(x+1);

    if(x)
    {

        s+= '(';
        s+=(x+'0');
        s+=')';
    }
//    cout<<"created "<<s<<endl;
    return s;

}

void del(string s)
{
    int pos=0, len = s.size();

    for(int i=0; i<len; i++)
    {
        if(s[i] == '(')
        {
            for(int j = i+1; j< len; j++)
            {
                if(s[j]==')')
                {
                    pos = atoi(s.substr(i+1, j).c_str());
                    break;
                }
            }
            s = s.substr(0, i);
            break;
        }
    }
//    printf("pos %d s %s\n", pos, s.c_str());

//    if(pos!=0)
        mp[s].insert(pos);


}


int main()
{


//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    while(n--)
    {

        string s;
        cin>>s;

        if(s=="crt")
        {
            cin>>s;
            cout<<"+ "<<create(s)<<endl;
        }
        else if(s == "del")
        {
            cin>>s;
            cout<<"- "<<s<<endl;
            del(s);
        }
        else
        {
            cin>>s;
            cout<<"r "<<s<<" -> ";
            del(s);
            cin>>s;

            cout<<create(s)<<endl;
        }

    }


    return 0;
}




