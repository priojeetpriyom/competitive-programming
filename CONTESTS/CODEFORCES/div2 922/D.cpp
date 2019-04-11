#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100


struct node{
    string s;
    ll score=0;
    int h;
    node(string ss, ll hh, int hhh) {
        s= ss;
        score = hh;
        h = hhh;
    }
    };

struct vector <node> vec;
int x_h;
ll calc(string s) {
    ll ret=0;
    int cnt=0;
    for(int i=s.size()-1; i>=0; i--) {
        if(s[i] == 's')
            ret+= cnt;
        else
            cnt++;
    }
    x_h = cnt;

    return ret;

}


bool cmp(node a, node b) {

//    if(a.h != b.h)
//        return a.h<b.h;
    string temp = a.s;
    temp+= b.s;
    ll aa = calc(temp);

    temp = b.s;
    temp+= a.s;
    ll bb = calc(temp);
    return aa>bb;
//    return a.score<b.score;

}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    string s;
    for(int i=0; i<n; i++)
    {
        cin>>s;
        calc(s);
        int temp_h = x_h;
        vec.push_back(node(s, calc(s), temp_h));
    }


    sort(vec.begin(), vec.end(), cmp);
    s.clear();
    for(auto i: vec)
        s+= i.s;

//    cout<<s<<endl;
    ll ans=0, cnt=0;

    for(int i=s.size()-1; i>=0; i--) {
        if(s[i] == 's')
            ans+= cnt;
        else
            cnt++;
    }

    cout<<ans<<endl;


    return 0;
}


