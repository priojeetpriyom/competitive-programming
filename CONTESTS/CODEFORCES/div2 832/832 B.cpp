#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int is_good[500];


string s, str;
int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin>>s;

    int len = s.size();
    for(int i=0; i<len; i++)
        is_good[s[i]-'a' ]=1;

    cin>>str;
//    bool has_star=false;
//    for(int i=0; i<str.size(); i++)
//    {
//        if(str[i] == '*') has_star=true;
//    }


    int q;
    cin>>q;

    while(q--)
    {

        cin>>s;
//        len = s.size();
        int flag=1;


//        if(str.size()-len ==1 && has_star)
//        {
//            flag_jump=1;
//        }
//        else if(len != str.size())
//            flag=0;


        int len_s = s.size(), len_str= str.size();
        int i,j;
        for( i=0, j=0; i<len_str && j<len_s; i++, j++)
        {

            if(str[i] == '?')
            {
                if(!is_good[ s[j]-'a' ]) flag=0;
            }
            else if(str[i] == '*')
            {
                if(len_str-i > len_s-j) {
                    j--;
                    continue;
                }
//                int fflag=0;
                if((!is_good[s[j]-'a']))
                {
                    while( j<len_s && (!is_good[s[j]-'a']) && (len_str-i < len_s-j) ) j++;
                    if(is_good[s[j]-'a' ]) flag=0;
//                    cout<<"j now "<<j<<endl;
                }
                else flag=0;

            }
            else
            {
                if(s[j] != str[i]) flag=0;
            }
        }
        if(str[i]=='*' && i<len_str) i++;
//        cout<<"i "<<i<<" j "<<j<<endl;
        if(i!= len_str || j != len_s) flag=0;
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;





    }



    return 0;
}


