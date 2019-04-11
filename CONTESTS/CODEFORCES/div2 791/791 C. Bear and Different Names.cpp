#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
string ans[100];
vector<string> chars;

void genDist()
{
    string s;
//    s = "A";
//    s += ('a'+2);
//    cout<<s<<endl;
    for(int i=0; i<26; i++)
    {
        s = "A";
        s+= ('a'+i);
        chars.push_back(s);
    }
    for(int i=0; i<26; i++)
    {

        s = "B";
        s+= ('a'+i);
        chars.push_back(s);
    }

//    for(int i=0; i<52; i++)
//        cout<<chars[i]<<endl;

}




int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    genDist();
    int n,k;
    cin>>n>>k;
    string str[100];
    int lim = n-k+1;
    for(int i=0; i<lim; i++)
    {
        cin>>str[i];
    }


    for(int i=0; i<lim; i++)
    {

        int l = i+k;
        if(str[i] == "YES")
        {
            map<string, int> used;
            for(int j=i; j< l; j++)
            {
                used[ans[j]]++;
            }
            for(int j = i; j< l; j++)
            {
                if(ans[j].length()==0)
                {
                    for(int k=0; k<chars.size(); k++)
                    {
                        if(!used.count(chars[k]))
                        {
                            ans[j] = chars[k];
                            used[chars[k]] = 1;
                            break;
                        }
                    }
                }
            }
        }
        else
        {
            if(!ans[i].size()) ans[i] ="Aa";
            for(int j = i+1; j< l; j++)
            {
                if(ans[j].length()==0)
                {
                    ans[j] = ans[i];
                    break;
                }
            }
        }
    }

    for(int i=0; i<n; i++)
        if(!ans[i].size() )
        {
            ans[i] = "Aa";
        }

    for(int i=0; i<n; i++)
        cout<<ans[i]<<" ";
    return 0;
}


