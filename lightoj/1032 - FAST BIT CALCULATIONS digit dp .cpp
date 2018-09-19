#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 35

ll dp[MX][MX] [MX];
int tc; //, vis[MX][MX] [MX];
int n;
//ll run=1;
string s;

ll rec(int len, int prev, int cons)
{
//        printf("s %d f %d turn %d\n", s, f, turn);
    if(len<0) return 0;
    if(!len) return prev+ max(0, (cons-1));


    ll &ret = dp[len][prev] [cons];
//    int  &v = vis[len][prev] [cons];
    if(ret != -1) return ret;

//    ret=1e9;
//    v= 1;

    ret = rec(len-1, prev, cons+1) + rec(len-1, prev+max(0, cons-1), 0);

//        printf("s %d f %d turn %d ret %d\n", s, f,turn,  ret);
    return ret;


}


ll calc() {

    ll ans=0;

    for(int i=1; i<s.size(); i++) {
        ans+= rec(i-1, 0, 1);
//        run++;
    }
//    printf("ans len-1 %lld\n", ans);
    int prev=0, cons=(s[0]=='1');
    for(int i=1; i<s.size(); i++) {
        if(s[i]=='0') {
            prev+= max(0, cons-1);
            cons=0;
        } else {
            ans+= rec(s.size()-i-1, prev+ max(0, cons-1), 0);
            cons++;
//            run++;
        }
    }
//    printf("ans len %lld\n", ans);


    prev=0, cons=0;
    for(int i=0; i<s.size(); i++) {
        if(s[i]=='0') {
            prev += max(0, cons-1);
            cons=0;
        }  else {
            cons++;
        }
    }

    ans+= prev+ max(0, cons-1);



    return ans;


}

void pre() {
    s.clear();
    int temp=n;

    while(n>0) {
        s+= (n&1) + '0';
        n>>=1;
    }

    if(s.size())
    {
        int len = s.size();

        for(int i=0; i<len/2; i++) {
            swap(s[i], s[len-i-1]);
        }

    } else
        s = '0';
//    cout<<s<<endl;
}


int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t;
    scanf("%d", &t);
    memset(dp, -1, sizeof dp);
    for(tc=1; tc<=t; tc++)
    {
        scanf("%d", &n);

        pre();
        ll ans = calc();
        printf("Case %d: %lld\n",tc, ans);

    }



    return 0;
}

