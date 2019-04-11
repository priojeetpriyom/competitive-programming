#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



int ara[30], f_s[200], f_t[200];
int vis[30];
queue<int> q;
int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);


    string s, t;
    cin>>s>>t;
    int len = s.size();


    for(int i=0; i<len; i++)
    {
        if(s[i]>='a' && s[i]<='z')
        {
//            ara[s[i]-'a' ]++;
//            vis[s[i]-'a']=1;
            f_s[s[i]-'a' ]++;
        }
    }
    len = t.size();
    for(int i=0; i<len; i++)
    {
        if(t[i]>='a' && t[i]<='z')
        {
//            ara[t[i]-'a' ]--;
//            vis[t[i]-'a']=1;
            f_t[ t[i]-'a' ]++;
        }
    }



    len = s.size();
    for(int i=0; i<len; i++)
    {
        if(s[i] == '?')
        {
            q.push(i);
        }
    }


    while(!q.empty()) {

        for(int i=0; i<26; i++) {

            while(f_s[i] < f_t[i] && !q.empty()) {
                s[q.front() ] = i+'a';
                q.pop();
                f_s[i]++;
            }
            f_s[i]-=f_t[i];

        }






    }






    cout<<s<<endl;



    return 0;
}


