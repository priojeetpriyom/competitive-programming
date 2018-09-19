#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 15
//int ara[11];
//ll ans[100100];
    string s;

int main()
{

//    freopen("out.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
//    int n;
    int n = s.size();
    int sum=0;
    bool hasZero=0;

    vector<int> vec[10];
    int cnt1=0, cnt2=2;
    for(int i=s.size()-1; i>=0; i--)
    {
        sum+= (s[i]-'0');
        if(s[i]=='0')
            hasZero=1;
//        vec[s[i]-'0'].push_back(i);
        if(s[i]=='1'|| s[i]=='4'|| s[i]=='7')
            vec[1].push_back(i);
        else if(s[i]=='2'|| s[i]=='5'|| s[i]=='8')
            vec[2].push_back(i);
    }

    if(s.size()==1)
    {
        cout<<((sum%3==0)? ((int)s[0]-48):-1)<<endl;
        return 0;
    }

    bool ok = false;
//    bool deleted = true;
//    cout<<"sum "<<sum<<endl;
    if(sum %3==1)
    {
//        cout<<"aise"<<endl;

        if(vec[1].size())
        {
            if(vec[1][0]!=0 || s[1]!='0')
            {
                s.erase(vec[1][0],1);
                ok = true;
                goto nextt;
            }

        }

        if(vec[2].size()>1)
        {

            s.erase(vec[2][0],1);
            s.erase(vec[2][1],1);
            ok = true;
            goto nextt;

        }
//        cout<<"aise"<<endl;
        if(s[0]%3==1 && s[1]=='0')
        {
            s.erase(0,1);
            ok= true;
            goto nextt;
        }

    }
    else if(sum %3==2)
    {
//        if(s[0]=='2' && s[1]=='0')
//        {
//
//        }
        if(vec[2].size())
        {

            if(vec[2][0]!=0 || s[1]!='0')
            {
                s.erase(vec[2][0],1);
                ok = true;
                goto nextt;
            }
        }

        {
            if(vec[1].size()>1)
            {

                s.erase(vec[1][0],1);
                s.erase(vec[1][1],1);
                ok = true;
                goto nextt;

            }
        }
        if(s[0]%3==2 && s[1]=='0')
        {
            s.erase(0,1);
            ok= true;
            goto nextt;
        }
    }
    else
    {
        ok = true;

    }

nextt:

//    cout<<ok<<endl;
//    if(!ok)
//    {
//        cout<<-1<<endl;
//        return 0;
//    }
//    else
    {
        bool zeroNow=0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]>'0')
            {

//                cout<<"aise i "<<i<<endl;
                s= s.substr(i);
                cout<<s<<endl;
                return 0;
//                    return 0;
//                    break;
            }
            else if(s[i]=='0')
                zeroNow=1;
            if(i == s.size()-1)
            {
                if(zeroNow)
                    cout<<0<<endl;
                else
                    cout<<-1<<endl;
                return 0;
            }

        }
        cout<<-1<<endl;
//        }
//        if(ok && s.size())
//        {
//            cout<<s<<endl;
////            cout<<"aise"<<endl;
////            bool printed = false;
////            for(char c: s)
////                if(c!= (char)-1)
////                    cout<<c, printed = true;
////            if(!printed)
////                cout<<-1;
////            cout<<endl;
//        }
//        else
//        {
////            if(hasZero && deleted )
////                cout<<0<<endl;
////            else
//                cout<<-1<<endl;
//        }
    }





    return 0;
}


