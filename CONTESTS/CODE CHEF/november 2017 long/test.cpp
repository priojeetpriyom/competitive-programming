#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 105
//int n;
    string s;
int n;

bool palin(string str, int len) {
//    cout<<str<<" "<<len<<endl;
    for(int i=0; i<len/2; i++) {
        if(str[i]!= str[len-i-1])
            return false;
    }

    return true;


}
int max_palin() {
    int mx=1;
    for(int i=0;i<n; i++) {
        for(int j=1; j<=n-i; j++)
        if(palin(s.substr(i,j), j)) {
            mx = max(mx, j);
        }
    }
    return mx;
}
int mn=1e9;

void gen(int pos) {

    if(pos==25) {
        n = s.size();
        mn = min(mn, max_palin());
        return;
    }

    for(int i=0; i<2; i++) {
        s+= ('a'+i);
        gen(pos+1);
        s.pop_back();
    }



}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout<<lim_int - ( (1LL)<<32)+1;


//    while(cin>>s) {
//            n = s.size();
        gen(0);
//        cout<<max_palin()<<endl;;
        cout<<mn<<endl;;
//    }


    return 0;
}

