#include <bits/stdc++.h>
//#include <iostream>
using namespace std;
typedef long long ll;

int into(int n) {
    int ans=1;
    for(int i=0; i<n; i++) {
        ans*=2;
        if(ans>1000)
            ans%=1000;
    }
    return ans;
}

string getBin(int n) {
    n = into(n)-2;
//    printf("n now %d\n", n);
    string s;
    while(n>0) {
        s+= (n%2)+'0';
        n/=2;
    }
//    cout<<s<<endl;
    if(s.size()<3) {
        if(s.size()==0)
            return "000";
        else if(s.size()==1) {
            return "00"+s;
        } else {
            s+='0';
            reverse(s.begin(), s.end());
            return s;
        }
    }
    else
        reverse(s.begin(), s.end());
//    cout<<"s now "<<s<<endl;
    return s.substr(s.size()-3);
}
int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int n;
    int t;
    cin>>t;
    while(t--) {
        cin>>n;
        cout<<n<<" ";
        cout<<getBin(n)<<endl;
    }

    return 0;
}




