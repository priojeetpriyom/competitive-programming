#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 110
#define MOD 1000000007


//ll dp [MX] [MX] [3];
//int n, k,d;
//
//ll rec(int left, int sum, int is_greater) {
//    if(sum==0)
//        return is_greater;
//    if(sum<0 || !left)
//        return 0;
//
//    ll &ret= dp[left] [sum] [is_greater];
//    if(~ret)
//        return ret;
//    ret=0;
//
//    for(int i = k; i>=1; i--)
//        ret+= rec(left-1, sum-i , is_greater | (i>=d));
//    if(ret>= MOD)
//        ret%=MOD;
//    return ret;
//}


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
//    memset(dp, -1, sizeof dp);


    int n, k;
    cin>>n>>k;

    string s, t;
    cin.ignore();
    cin>>t;

    //if(n==1) {
        //if(t[0]=='.')
            //t[0]='1';
        //cout<<t<<endl;
        //return 0;
    //}


    s = " ";
    s+= t;

    int len = t.size();

    bool ok = false;
    for(int i=1; i<= len-k; i++) {
        if(s[i]=='.' || s[i]!= s[i+k]) {
            ok = true;
            break;
        }
    }


    if(!ok) {
        cout<<"No"<<endl;
        return 0;
    }




    for(int i=1; i<= len-k; i++) {
        if(s[i]=='.') {
            s[i] = !(s[i+k]-'0')+'0';
        }
    }

    for(int i=len-k+1; i<= len; i++) {
        if(s[i]=='.') {
            s[i] = !(s[i-k]-'0')+'0';
        }
    }

    cout<<s.substr(1)<<endl;

    return 0;
}



