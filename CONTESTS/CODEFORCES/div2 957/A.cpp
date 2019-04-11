#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100
int dp[200][300];
int n;
    string s;
int rec(int pos, int prev) {

    if(pos==n)
        return 1;
//    printf("pos %d\n", pos);
    if(s[pos]!='?') {
        if(prev==s[pos])
            return 0;
        else
        return rec(pos+1, s[pos]);
    }
    int& ret = dp[pos] [prev];

    if(~ret)
        return ret;
    ret=0;
    if(prev==0)
        ret = rec(pos+1, 'C') +rec(pos+1, 'M') +rec(pos+1, 'Y');
    else if(prev=='Y') {
        ret = rec(pos+1, 'C') +rec(pos+1, 'M');
    }else if(prev=='C') {

        ret = rec(pos+1, 'Y') +rec(pos+1, 'M');
    } else {

        ret = rec(pos+1, 'C') +rec(pos+1, 'Y');
    }
    return ret;

}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
//    int n;
    cin>>n;
    cin>>s;
    int ques= (s[0]=='?');
    for(int i=1; i<s.size(); i++)
    {
        if(s[i] == '?')
            ques++;
        else if(s[i] == s[i-1])
        {
//            printf("aise %c %c\n",s[i], s[i-1]);
            cout<<"No"<<endl;
            return 0;
        }
    }
//    cout<<rec(0, 0)<<endl;
    if(rec(0,0)<2)
    {
        cout<<"No"<<endl;
        return 0;
    }
    else
        cout<<"Yes"<<endl;


    return 0;
}


