#include <bits/stdc++.h>

using namespace std;

stack <int> s;
//typedef ll long long;
string str[500100];
char c;

string comp(string change, string &cmp, int len_change, int len_cmp)
{


    if(change <= cmp)
    {
//        if(change.size())
            cmp = change.substr(0, len_change);
        return change;
    }
    else
    {
        for(int i=0; i<len_change; i++)
        {
            if(change[i] > cmp[i])
            {
                change = change.substr(0, i);
//                if(change.size())
                    cmp = min(cmp, change);
                return change;
            }
        }
    }

}


int main()
{
//   freopen("out.txt", "w", stdout);

    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>c>>str[i];
//        cout<<c<<"  "<<str[i]<<endl;
//        if(s.empty() )
//        {
//            s.push(i);
//        }
//        else if((str[i] <= str[s.top()] ))
//        {
//            while(!s.empty() && str[i] <= str[s.top()])
//            {
//                s.pop();
//            }
//            s.push(i);
//        } else if(str[i]<str[i-1])
//            s.push(i);
    }
    string ss = str[n-1];
    for(int i = n-1; i>=0; i--) {
        if(str[i] > ss) {
            int len = str[i].length();
            for(int j=0; j<len; j++) {
                if(str[i][j] > ss[j]) {
                    str[i] = str[i].substr(0, j);
                    break;
                }
            }
        }
            ss = str[i];
    }


    for(int i=0; i<n; i++)
        cout<<"#"<<str[i]<<endl;

    return 0;
}

